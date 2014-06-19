-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- 主机: localhost
-- 生成日期: 2014-06-19 17:50:14
-- 服务器版本: 5.5.37-0ubuntu0.14.04.1
-- PHP 版本: 5.5.9-1ubuntu4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- 数据库: `house`
--

-- --------------------------------------------------------

--
-- 表的结构 `book`
--

CREATE TABLE IF NOT EXISTS `book` (
  `bookNo` int(11) NOT NULL AUTO_INCREMENT,
  `rentId` int(11) NOT NULL,
  `roomId` int(11) NOT NULL,
  `bookM` int(11) NOT NULL,
  `vTime` int(11) DEFAULT NULL,
  `bookTime` int(11) DEFAULT NULL,
  `startDate` date DEFAULT NULL,
  `salesman` varchar(20) DEFAULT NULL,
  `bookData` date DEFAULT NULL,
  PRIMARY KEY (`bookNo`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=40003 ;

--
-- 转存表中的数据 `book`
--

INSERT INTO `book` (`bookNo`, `rentId`, `roomId`, `bookM`, `vTime`, `bookTime`, `startDate`, `salesman`, `bookData`) VALUES
(1234, 12, 123, 300, 50, 12, '2014-06-18', '112', '2014-06-18'),
(40000, 1, 121, 0, 0, 0, '2014-06-17', '', '2014-06-18'),
(40001, 30003, 115, 0, 0, 0, '2014-06-18', '', '2014-06-18'),
(40002, 30001, 118, 100, 20, 2, '2014-06-19', '100', '2014-06-19');

-- --------------------------------------------------------

--
-- 表的结构 `contract`
--

CREATE TABLE IF NOT EXISTS `contract` (
  `contractNo` int(11) NOT NULL AUTO_INCREMENT,
  `bookNo` int(11) NOT NULL COMMENT '预订编号',
  `customerName` varchar(20) NOT NULL,
  `roomId` int(11) NOT NULL,
  `depoistM` int(11) NOT NULL COMMENT '押金',
  `endDate` date NOT NULL COMMENT '结束日期',
  `rentDate` int(11) NOT NULL,
  `moneyShould` int(11) NOT NULL,
  `salesMan` int(11) NOT NULL,
  `signDate` date NOT NULL,
  `remark` varchar(100) CHARACTER SET utf8 DEFAULT NULL,
  PRIMARY KEY (`contractNo`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COMMENT='合同' AUTO_INCREMENT=27 ;

--
-- 转存表中的数据 `contract`
--

INSERT INTO `contract` (`contractNo`, `bookNo`, `customerName`, `roomId`, `depoistM`, `endDate`, `rentDate`, `moneyShould`, `salesMan`, `signDate`, `remark`) VALUES
(2, 0, 'af', 103, 1500, '2014-06-18', 46, 1400, 1234, '2014-06-18', ''),
(4, 0, 'af', 103, 1500, '2014-06-18', 45, 1500, 123, '2014-06-18', ''),
(7, 0, 'af', 111, 1600, '2014-06-19', 48, 1600, 123, '2014-06-19', ''),
(13, 0, 'zx', 118, 12, '2014-06-19', 12, 12, 123, '2014-06-19', ''),
(26, 0, 'dch', 113, 12, '2014-06-19', 12, 12, 123, '2014-06-19', '');

-- --------------------------------------------------------

--
-- 表的结构 `depoist`
--

CREATE TABLE IF NOT EXISTS `depoist` (
  `roomId` int(11) NOT NULL,
  `depositM` int(11) DEFAULT NULL,
  `customerId` int(11) DEFAULT NULL,
  `customerName` varchar(11) DEFAULT NULL,
  PRIMARY KEY (`roomId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `depoist`
--

INSERT INTO `depoist` (`roomId`, `depositM`, `customerId`, `customerName`) VALUES
(1002, 42, 12, NULL),
(1003, 10, 123, 'zx');

-- --------------------------------------------------------

--
-- 表的结构 `deposit`
--

CREATE TABLE IF NOT EXISTS `deposit` (
  `chargeNumber` int(11) NOT NULL AUTO_INCREMENT COMMENT '收费编号',
  `depositMoney` int(11) NOT NULL COMMENT '定金金额',
  `chargeDate` date NOT NULL COMMENT '收费日期',
  `contractNo` int(11) NOT NULL COMMENT '合同编号',
  `customerName` varchar(20) CHARACTER SET utf8 NOT NULL COMMENT '预定客户',
  `roomId` int(11) NOT NULL COMMENT '预定房屋编号',
  `remark` varchar(100) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`chargeNumber`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COMMENT='押金' AUTO_INCREMENT=50001 ;

--
-- 转存表中的数据 `deposit`
--

INSERT INTO `deposit` (`chargeNumber`, `depositMoney`, `chargeDate`, `contractNo`, `customerName`, `roomId`, `remark`) VALUES
(50000, 500, '2014-06-10', 10, 'CSS', 100, '');

-- --------------------------------------------------------

--
-- 表的结构 `frontMoney`
--

CREATE TABLE IF NOT EXISTS `frontMoney` (
  `chargeNumber` int(11) NOT NULL AUTO_INCREMENT COMMENT '收费编号',
  `frontMoney` int(11) NOT NULL COMMENT '定金金额',
  `frontNumber` int(11) NOT NULL COMMENT '预定金编号',
  `chargeDate` date NOT NULL COMMENT '收费日期',
  `frontCustomer` varchar(20) CHARACTER SET utf8 NOT NULL COMMENT '预定客户',
  `frontHouse` int(11) NOT NULL COMMENT '预定房屋编号',
  `remark` varchar(100) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`chargeNumber`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COMMENT='定金' AUTO_INCREMENT=40002 ;

--
-- 转存表中的数据 `frontMoney`
--

INSERT INTO `frontMoney` (`chargeNumber`, `frontMoney`, `frontNumber`, `chargeDate`, `frontCustomer`, `frontHouse`, `remark`) VALUES
(40000, 0, 10, '2014-06-10', '20001', 100, ''),
(40001, 0, 0, '2014-06-10', '', 0, '');

-- --------------------------------------------------------

--
-- 表的结构 `lessee`
--

CREATE TABLE IF NOT EXISTS `lessee` (
  `customerId` int(11) NOT NULL AUTO_INCREMENT,
  `customerName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `nativePlace` varchar(50) CHARACTER SET utf8 NOT NULL COMMENT '工作地址',
  `phoneNumber` varchar(20) CHARACTER SET utf8 NOT NULL,
  `sex` int(10) NOT NULL,
  `idCard` varchar(20) CHARACTER SET utf8 NOT NULL COMMENT '身份证号',
  `number` int(11) NOT NULL COMMENT '租住人数',
  `remark` varchar(100) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`customerId`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=20021 ;

--
-- 转存表中的数据 `lessee`
--

INSERT INTO `lessee` (`customerId`, `customerName`, `nativePlace`, `phoneNumber`, `sex`, `idCard`, `number`, `remark`) VALUES
(20001, 'CSS', '11', '111', 0, '120', 1, '1'),
(20002, 'cg', '1', '17000100028', 1, '111', 1, '1'),
(20003, 'zx', 'tjnu', '', 0, '411', 0, ''),
(20004, '整', '天津', '', 1, '', 0, ''),
(20005, 'xx', 'tjnu', '155', 0, '', 0, ''),
(20006, 'sa', '', '', 1, '', 0, ''),
(20007, 'female', '', '', 1, '', 0, ''),
(20008, 'man', '', '', 0, '', 0, ''),
(20009, 'lijufu', '北京', '010', 0, '', 0, ''),
(20011, 'shanda', '法国', '', 0, '', 0, '外国人'),
(20012, 'fusa', '', '', 1, '', 0, ''),
(20013, 'zeng', 'ccb', '', 0, '', 0, ''),
(20014, 'laoshi', '', '', 0, '', 0, ''),
(20015, '3q', '', '', 0, '', 0, ''),
(20016, '开发', '', '', 0, '', 0, ''),
(20018, '往往', '', '', 0, '', 0, ''),
(20019, 'dh', '', '', 0, '', 0, 'short of money'),
(20020, 'superman', '', '', 145589856, '', 0, '');

-- --------------------------------------------------------

--
-- 表的结构 `login`
--

CREATE TABLE IF NOT EXISTS `login` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `user` varchar(20) CHARACTER SET utf8 NOT NULL,
  `pwd` varchar(20) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10001 ;

--
-- 转存表中的数据 `login`
--

INSERT INTO `login` (`ID`, `user`, `pwd`) VALUES
(10000, 'admin', 'admin');

-- --------------------------------------------------------

--
-- 表的结构 `rent`
--

CREATE TABLE IF NOT EXISTS `rent` (
  `chargeNumber` int(11) NOT NULL AUTO_INCREMENT COMMENT '收费编号',
  `rentDate` date NOT NULL COMMENT '租房日期',
  `moneyShould` int(11) NOT NULL COMMENT '应付资金',
  `moneyAlready` int(11) NOT NULL COMMENT '已付租金',
  `arrearage` int(11) NOT NULL COMMENT '欠费',
  `customerName` varchar(20) CHARACTER SET utf8 NOT NULL COMMENT '租户姓名',
  `chargeDate` date NOT NULL COMMENT '收费日期',
  `remark` varchar(100) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`chargeNumber`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COMMENT='租金' AUTO_INCREMENT=60002 ;

--
-- 转存表中的数据 `rent`
--

INSERT INTO `rent` (`chargeNumber`, `rentDate`, `moneyShould`, `moneyAlready`, `arrearage`, `customerName`, `chargeDate`, `remark`) VALUES
(60000, '2014-05-10', 1000, 500, 500, 'CSS', '2014-06-10', ''),
(60001, '2014-06-06', 2500, 2500, 0, 'cg', '2014-06-07', '');

-- --------------------------------------------------------

--
-- 表的结构 `repay`
--

CREATE TABLE IF NOT EXISTS `repay` (
  `roomId` int(11) NOT NULL,
  `customerId` int(11) DEFAULT NULL,
  `customerName` varchar(20) NOT NULL,
  `moneyShould` int(11) NOT NULL,
  `moneyEver` int(11) DEFAULT NULL,
  `moneyOwn` int(11) DEFAULT NULL,
  `yearNo` int(11) DEFAULT NULL,
  `monthNo` int(11) DEFAULT NULL,
  PRIMARY KEY (`roomId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `repay`
--

INSERT INTO `repay` (`roomId`, `customerId`, `customerName`, `moneyShould`, `moneyEver`, `moneyOwn`, `yearNo`, `monthNo`) VALUES
(103, 0, 'af', 0, 0, 0, NULL, 12),
(113, NULL, 'dch', 12, NULL, NULL, NULL, 12),
(116, 0, 'zx', 0, 0, 0, NULL, 0),
(118, 0, 'zx', 12, NULL, -88, NULL, 12);

-- --------------------------------------------------------

--
-- 表的结构 `roomInfo`
--

CREATE TABLE IF NOT EXISTS `roomInfo` (
  `roomId` int(11) NOT NULL AUTO_INCREMENT,
  `renterId` int(11) NOT NULL DEFAULT '0' COMMENT '租户ID',
  `lessee` int(11) NOT NULL DEFAULT '0' COMMENT '房东',
  `roomType` varchar(20) CHARACTER SET utf8 NOT NULL,
  `location` varchar(50) CHARACTER SET utf8 NOT NULL,
  `realNum` int(11) NOT NULL COMMENT '实际面积',
  `area` int(11) NOT NULL,
  `circumstance` varchar(20) CHARACTER SET utf8 NOT NULL COMMENT '装修状况',
  `price` int(11) NOT NULL,
  `remark` varchar(100) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`roomId`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=118 ;

--
-- 转存表中的数据 `roomInfo`
--

INSERT INTO `roomInfo` (`roomId`, `renterId`, `lessee`, `roomType`, `location`, `realNum`, `area`, `circumstance`, `price`, `remark`) VALUES
(102, 10012, 0, '3-2', '爱情公寓3601号', 180, 200, '好', 5000, '环境优雅，特别适合单身男女青年居住'),
(103, 0, 0, '3-2', '姚村公寓10号楼103', 110, 120, '良好', 2500, '安静环境'),
(104, 0, 0, '', '姚村10号楼202号', 0, 0, '', 0, ''),
(105, 0, 0, '', '姚村5号楼201', 100, 110, '', 1500, ''),
(106, 0, 0, '3-2', '姚村16号楼302', 110, 120, '良好', 2500, '价格便宜，环境优雅'),
(107, 0, 0, '', '1号楼1单元101', 111, 123, '较好', 3000, '环境舒适'),
(108, 0, 0, '3-2', '1号楼1单元102', 111, 123, '一般', 2000, '宽敞阳台'),
(109, 0, 0, '3-3', '付村1号楼302', 160, 180, '豪华', 5500, '附近有豪华版手抓饼免费提供'),
(110, 0, 0, '1-1', 'tjnu', 15, 20, '', 20, 'hehe'),
(111, 30007, 0, '123', '123', 132, 123, '132', 312, '132'),
(112, 0, 0, '', '13', 0, 0, '', 0, ''),
(113, 0, 0, '', '14', 0, 0, '', 0, ''),
(115, 30007, 0, '', '16', 0, 0, '', 0, ''),
(116, 0, 0, '', '17', 0, 0, '', 0, ''),
(117, 0, 0, '', 'Tianjin Normal Uinversity 15#', 30, 50, '', 500, 'good');

-- --------------------------------------------------------

--
-- 表的结构 `wanted`
--

CREATE TABLE IF NOT EXISTS `wanted` (
  `customerId` int(11) NOT NULL AUTO_INCREMENT COMMENT '求租客户编号',
  `customerName` varchar(20) NOT NULL COMMENT '求租客户姓名',
  `phoneNumber` varchar(20) NOT NULL COMMENT '电话',
  `roomType` varchar(20) DEFAULT NULL COMMENT '房型要求',
  `area` int(11) DEFAULT NULL COMMENT '面积要求',
  `circumstance` varchar(20) DEFAULT NULL COMMENT '装修要求',
  `price` int(11) DEFAULT NULL COMMENT '意向价位',
  `roomId` int(11) DEFAULT NULL COMMENT '意向房屋编号',
  `sj` int(11) NOT NULL COMMENT '时间',
  `remark` varchar(100) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`customerId`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='求租' AUTO_INCREMENT=30011 ;

--
-- 转存表中的数据 `wanted`
--

INSERT INTO `wanted` (`customerId`, `customerName`, `phoneNumber`, `roomType`, `area`, `circumstance`, `price`, `roomId`, `sj`, `remark`) VALUES
(10012, 'zx', '\0', '', 0, '', 0, 102, 0, ''),
(30001, 'cg', '\0', '3-2', 150, '', 0, 0, 0, ''),
(30005, 'csb', '\0', '', 0, '', 0, 0, 0, ''),
(30007, 'dch', '\0', '3-2', 50, '', 0, 0, 0, ''),
(30008, '11', '\0', '', 0, '', 0, 0, 0, ''),
(30009, 'ww', '\0', '', 0, '', 0, 0, 0, ''),
(30010, 'hhq', '\0', '', 0, '', 0, 115, 0, '');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
