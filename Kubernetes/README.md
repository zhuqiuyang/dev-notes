### 概念

- Clutster 由`Master(管理), Worker Node 组成`
- Master
  - `Controller`: A control loop that 监控 cluster 共享的`state`
  - `apiserver`: 暴露控制 API
  - `kube-controller-manager`: component that run `controller`
- Node(Workder) (物理/虚拟机)
  - Pod (k8s 的最小单位), 其内运行 Container
    > https://kubernetes.io/docs/tutorials/kubernetes-basics/explore/explore-intro/
  - `kubelet`: 负责与 Master 通信, 并管理 Pod
    - `health check monitor` is the Kubelet agent
  - `kube-proxy` run on eache node: 负责实现`Services`的 虚拟 IP, 或者`External Name`(需要`kube-dns`)
- Service: 通过 Service 向 K8S cluster 外暴露服务
  - `Service` 是在 Pod 之上的抽象, 允许`Pod` die or replicate 而不影响 `application`.
    > Service YAML 定义(核心): https://kubernetes.io/docs/concepts/services-networking/service/
  - Services match a set of Pods using `labels and selectors`
  - `Roll update`: 保证了 pod 更新时, 有回滚到上一版本(stable)的功能.

### kubectl cmd Test

> https://kubernetes.io/docs/tutorials/k8s201/

```sh
# 创建 deployment 通过kind指定
kubectl create -f https://k8s.io/examples/application/deployment.yaml
kubectl get deployment
# 删除 deployment
kubectl delete deployment nginx-deployment

kubectl create -f https://k8s.io/examples/service/nginx-service.yaml
kubectl get services
kubectl delete service nginx-service

```
