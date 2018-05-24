## 简介

与平台, 语言无关, 速度快(移位操作)

## Protocol Buffer Basics: Go

> https://developers.google.com/protocol-buffers/docs/gotutorial

### Why use protocol buffers?

`.proto` file 用于描述 data structure.

* pb compiler 会根据描述创建一个 class, 可以自动的 encode 和 parse 二进制数据.
* 同时提供`getter`和`setter`for field.

## Language Guide (proto3)

> https://developers.google.com/protocol-buffers/docs/proto3

### 定义 protocol 格式

定义`message`

* `repeat` 对应数组
* map 对应 key-value

```proto
syntax = "proto3";

message SearchRequest {
  string query = 1;
  int32 page_number = 2;
  int32 result_per_page = 3;
}
```

#### Assigning Field Numbers (易混淆)

message 中的每一个 field 必须有一个唯一的 number

* `field numbers`用于标示`field`(二进制中)

### Enumerations

希望 field 值范围可`pre-define`好

## Encoding

> https://developers.google.com/protocol-buffers/docs/encoding

```sh
message Test1 {
  optional int32 a = 1;
}
```

set `a`为`150`, 序列化后为 3 bytes:

```text
08 96 01
```

but what does it mean? Read on...

#### Base 128 Varints

`varint`是用 one or more bytes 序列化 integer.

* 其中每个 byte(除了 last byte), msb(最高位) set 成`1`
  * single byte, 其本身就是 last byte,所以 msb 不设置.(用于表示还有更多 byte)
* **`least significant group first`** 权重小的 byte 在前. (反序存储?)

#### Message Structure

在二进制中, message 只把`field's number`当做 key, `name`和`type`只在 decode 时用到.(程序使用, 因为二进制不需要类型)

* message encoded 过程中, the `keys and values` 会合并成 a byte stream.
* decodeing 时, parser skip 不识别的`field`(便于拓展)
* To this end, the `key` for each pair in a `wire-format` message is actually two values
  * the `field number` 和 a `wire type`(标示数据长度, 占多少 byte)

available`wire type`:

| Type | Meaning          | Used for                                                 |
| ---- | ---------------- | -------------------------------------------------------- |
| 0    | Varint           | int32, int64, uint32, uint64, sint32, sint64, bool, enum |
| 1    | 64-bit           | fixed64, sfixed64, double                                |
| 2    | Length-delimited | string, bytes, embedded messages, packed repeated fields |
| 3    | Start group      | groups (deprecated)                                      |
| 4    | End group        | groups (deprecated)                                      |
| 5    | 32-bit           | fixed32, sfixed32, float                                 |

* `Each key` in the streamed message is a `varint` with the value `(field_number << 3) | wire_type`

#### More Value Types
