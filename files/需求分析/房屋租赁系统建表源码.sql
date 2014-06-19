create database house;   

use house;  

CREATE TABLE `customer` (
`customerId` int(11) NOT NULL,
`customerName` char(20) NOT NULL,
`Sex` char(5) NOT NULL,
`NativePlace` char(50) NOT NULL,
  `idCard` char(20) NOT NULL,
  `roomId` int(11) NOT NULL,
  `inDate` datetime NOT NULL,
  `leaveDate` datetime NOT NULL,
  `bargain` char(20) NOT NULL,
  `price` int(11) NOT NULL,
  `remark` char(100) NOT NULL,
  PRIMARY KEY (`customerId`)
) ENGINE = InnoDB
CHARACTER SET gb2312 COLLATE gb2312_chinese_ci;

CREATE TABLE `login` (
`ID` int(11) NOT NULL,
`user` char(20) NOT NULL,
`pwd` char(20) NOT NULL,
PRIMARY KEY (`ID`)
) ENGINE = InnoDB
CHARACTER SET gb2312 COLLATE gb2312_chinese_ci;

CREATE TABLE `renter` (
   `renterId` int(11) NOT NULL,
   `Name` char(20) NOT NULL,
   `Contact` char(20) NOT NULL,
   `Bargain` char(20) NOT NULL,
   `Price` int(11) NOT NULL,
   `Remark` char(50) DEFAULT NULL,
   PRIMARY KEY (`renterId`) 
) ENGINE = InnoDB
CHARACTER SET gb2312 COLLATE gb2312_chinese_ci;

CREATE TABLE `roomInfo` (
`roomId` int(11) NOT NULL,
`renterid` int(11) NOT NULL,
  `roomtype` char(20) NOT NULL,
`location` char(50) NOT NULL,
`floor` int(11) NOT NULL,
`ratingNum` int(11) NOT NULL,
`realNum` int(11) NOT NULL,
`area` int(11) NOT NULL,
`price` int(11) NOT NULL,
`air` char(10) NOT NULL,
`phone` char(10) NOT NULL,
`tv` char(10) NOT NULL,
`washer` char(10) NOT NULL,
`internet` char(10) NOT NULL,
`fridge` char(10) NOT NULL,
`remark` char(100) NOT NULL,
PRIMARY KEY (`roomId`)
) ENGINE = InnoDB
CHARACTER SET gb2312 COLLATE gb2312_chinese_ci;
