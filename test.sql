create table `pay` (
    `order_id` varchar(64),
    `user_id` int(10),
    `user_area` int(10),
    `recharge` int(10),
    `status` Tinyint(1),
    PRIMARY KEY(`order_id`)
    )engine=InnoDB default charset=utf8;
    
insert into pay (order_id, user_id, user_area, recharge, `status`) values ("1", 10001, 1, 100, 1);
insert into pay (order_id, user_id, user_area, recharge, `status`) values ("2", 10002, 2, 100, 0);
insert into pay (order_id, user_id, user_area, recharge, `status`) values ("3", 10003, 3, 100, 1);
insert into pay (order_id, user_id, user_area, recharge, `status`) values ("4", 10004, 1, 100, 1);
insert into pay (order_id, user_id, user_area, recharge, `status`) values ("5", 10005, 2, 100, 1);
insert into pay (order_id, user_id, user_area, recharge, `status`) values ("6", 10001, 1, 1000, 1);