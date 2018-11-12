package com.imooc.firstapp.repository;

import com.imooc.firstapp.domain.User;
import org.springframework.stereotype.Repository;

import java.util.Collection;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * {@link com.imooc.firstapp.domain.User}
 */

@Repository
public class UserRepository {

    /**
     * 采用内存性存储
     */
    private final ConcurrentMap<Integer, User> repository = new ConcurrentHashMap<>();

    private final static AtomicInteger idGenerator =
            new AtomicInteger();

    public  boolean Save(User user) {

        // ID 从 1 增长
        Integer id = idGenerator.incrementAndGet();
        // 设置 ID
        user.setId(id);
        return repository.put(id, user)  == null;

    }

    public Collection<User> findAll(){
        return repository.values();
    }
}
