package com.imooc.firstapp.User;

import com.imooc.firstapp.domain.User;
import com.imooc.firstapp.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class UserController {
    private final UserRepository userRepository;

    /**
     * spring 框架自动完成注入
     * @param userRepository
     */
    @Autowired
    public UserController(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @PostMapping("/person/save")
    public User save(@RequestParam String name) {
        User user = new User();
        user.setName(name);
        user.nickName = "defaultNick";

        if (userRepository.Save(user)) {
            System.out.printf("用户 %s 保存成功 \n", user);
        }

        return user;
    }
}
