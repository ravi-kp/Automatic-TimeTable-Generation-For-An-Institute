-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Oct 31, 2019 at 04:45 PM
-- Server version: 10.4.8-MariaDB
-- PHP Version: 7.3.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `timetable`
--

-- --------------------------------------------------------

--
-- Table structure for table `course`
--

CREATE TABLE `course` (
  `course_no` varchar(100) DEFAULT NULL,
  `course_name` varchar(50) NOT NULL,
  `department_code` varchar(50) NOT NULL,
  `instructor` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `course`
--

INSERT INTO `course` (`course_no`, `course_name`, `department_code`, `instructor`) VALUES
('EE 201 ', 'Data Analysis', 'CSE', 'Mahadeva Prasanna'),
('CS 201', 'Data Structures and Algorithms', 'CSE', 'Sandeep R.B'),
('CS 211', 'Data Structures and Algorithms Lab', 'CSE', 'Sandeep R.B'),
('CS 203', 'Discrete Structures ', 'CSE', 'Prof. G. Nagaraja'),
('HS 201', 'Economics ', 'HS', 'Gopal Sharan Parash'),
('CS403', 'Graph Theory', 'CSE', 'Sagnik Sen'),
('CS 213', 'Software Systems Lab ', 'CSE', 'Ramchandra Phawade');

-- --------------------------------------------------------

--
-- Table structure for table `course_table`
--

CREATE TABLE `course_table` (
  `course_name` varchar(50) NOT NULL,
  `semester` varchar(40) NOT NULL,
  `no_of_students` int(11) NOT NULL,
  `Department` varchar(40) NOT NULL,
  `lab` varchar(10) NOT NULL,
  `preference` int(11) NOT NULL,
  `preffered_room` varchar(40) DEFAULT NULL,
  `preffered_slot` varchar(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `course_table`
--

INSERT INTO `course_table` (`course_name`, `semester`, `no_of_students`, `Department`, `lab`, `preference`, `preffered_room`, `preffered_slot`) VALUES
('Accounting_Financial_management', '7', 70, 'CSE,ME,EE', 'n', 0, '', NULL),
('Analog_circuit_lab', '5', 50, 'EE', 'y', 0, '', NULL),
('Astrophysics_for_engineers', '7', 70, 'CSE,ME,EE', 'n', 0, '', NULL),
('calculus', '1', 120, 'CSE', 'n', 0, '', NULL),
('Chemistry', '1', 120, 'CSE', 'n', 0, '', NULL),
('chemistry_lab', '1', 80, 'CSE', 'y', 0, '', NULL),
('Communication_Lab', '7', 50, 'EE', 'y', 0, '', NULL),
('Complex_analysis', '3', 50, 'EE', 'n', 0, '', NULL),
('Computer_architecture ', '5', 70, 'CSE,EE', 'n', 0, '', NULL),
('Computer_Architecture_lab', '5', 50, 'CSE,EE', 'y', 0, '', NULL),
('Control_system', '5', 70, 'ME,EE', 'n', 0, '', NULL),
('Control_system_lab ', '5', 70, 'ME,EE', 'y', 0, '', NULL),
('Database_and_information_system', '5', 50, 'CSE', 'n', 0, '', NULL),
('Database_information_system_lab', '5', 50, 'CSE', 'y', 0, '', NULL),
('Data_Analysis', '3', 80, 'CSE,ME,EE', 'n', 0, '', NULL),
('Data_structure_and_algo', '3', 50, 'CSE', 'n', 0, '', NULL),
('Data_Structure_and_algo_lab', '3', 50, 'CSE', 'y', 0, '', NULL),
('Differential_equation_II', '3', 50, 'EE', 'n', 0, '', NULL),
('Digital_system_lab', '5', 50, 'CSE,EE', 'y', 0, '', NULL),
('Discrete_structure ', '3', 50, 'CSE', 'n', 0, '', NULL),
('Distributed_System', '7', 50, 'CSE', 'n', 0, '', NULL),
('Economics', '3', 80, 'CSE,ME,EE', 'n', 0, '', NULL),
('Electronics_device ', '3', 50, 'EE', 'n', 0, '', NULL),
('Elementary_algebra', '5', 50, 'CSE', 'n', 0, '', NULL),
('Engineering_graphics', '1', 120, 'CSE', 'n', 0, '', NULL),
('Engineering_graphics_lab', '1', 80, 'CSE', 'n', 0, '', NULL),
('Engineering_lab', '1', 80, 'CSE', 'y', 0, '', NULL),
('Engineering_Materials', '3', 50, 'ME', 'n', 0, '', NULL),
('Engineering_mechanics ', '3', 50, 'ME', 'n', 0, '', NULL),
('Finite_element_analysis', '7', 50, 'ME', 'n', 0, '', NULL),
('Graph_theory', '5and7', 60, 'CSE', 'n', 0, '', NULL),
('Heat_transfer', '5', 50, 'ME', 'n', 0, '', NULL),
('Introduction_to_combustion ', '7', 50, 'ME', 'y', 0, '', NULL),
('Introduction_to_philosophy', '5', 80, 'CSE,ME,EE', 'n', 0, '', NULL),
('Introduction_to_probability', '5', 50, 'EE', 'n', 0, '', NULL),
('Kinematics_dynamics_of_machine', '5', 50, 'ME', 'n', 0, '', NULL),
('Machine_drawing_lab', '3', 50, 'ME', 'y', 0, '', NULL),
('Machine_learning', '5and7', 60, 'CSE,EE', 'n', 0, '', NULL),
('Manufacturing_processes_II', '5', 50, 'ME', 'n', 0, '', NULL),
('Manufacturing_Process_Lab', '7', 50, 'ME', 'y', 0, '', NULL),
('Mechanical_measurement_lab', '5', 50, 'ME', 'y', 0, '', NULL),
('Network_theory', '3', 50, 'EE', 'n', 0, '', NULL),
('Power_electronics_lab ', '5', 50, 'EE', 'y', 0, '', NULL),
('Power_system', '5', 50, 'EE', 'n', 0, '', NULL),
('Power_system_dynamic_and_control', '7', 50, 'EE', 'n', 0, '', NULL),
('Quantum_Physics', '1', 120, 'CSE', 'n', 0, '', NULL),
('Reinforcement_learning', '7', 50, 'CSE', 'y', 0, '', NULL),
('Signal_and_system', '3', 50, 'EE', 'n', 0, '', NULL),
('Software_system_lab', '3', 50, 'CSE', 'y', 0, '', NULL),
('Solid_mechanics_lab', '5', 50, 'ME', 'y', 0, '', NULL),
('Statistical_Mechanics', '7', 80, 'CSE,ME,EE', 'n', 0, '', NULL),
('Technoloical_entrepreneurship', '7', 70, 'CSE,ME,EE', 'n', 0, '', NULL),
('Thermodynamics', '3', 50, 'ME', 'n', 0, '', NULL),
('Vibration_of_linear_system', '7', 50, 'ME', 'n', 0, '', NULL),
('VLSI_Design', '7', 50, 'EE', 'n', 0, '', NULL),
('Wireless_communication ', '7', 50, 'EE', 'n', 0, '', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `department`
--

CREATE TABLE `department` (
  `dept_id` int(100) NOT NULL,
  `dept_code` varchar(20) NOT NULL,
  `dept_name` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`dept_id`, `dept_code`, `dept_name`) VALUES
(1, 'CSE', 'Computer Science Engineering'),
(2, 'EE', 'Electrical Engineering'),
(6, 'HS', 'Department of Humanities and Social Sciences'),
(5, 'Math Dept', 'Math department'),
(3, 'ME', 'Mechanical Engineering');

-- --------------------------------------------------------

--
-- Table structure for table `facultyreg`
--

CREATE TABLE `facultyreg` (
  `fac_id` int(100) NOT NULL,
  `name` varchar(20) NOT NULL,
  `email` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `facultyreg`
--

INSERT INTO `facultyreg` (`fac_id`, `name`, `email`) VALUES
(1, 'Gayathri Ananthanara', 'gayathri@iitdh.ac.in'),
(11, 'Gopal Sharan Parash', 'gp@iitdh.ac.in'),
(2, 'Kedar Khandeparkar', 'kedark@iitdh.ac.in'),
(12, 'Mahadeva Prasanna', 'prasanna@iitdh.ac.in'),
(3, 'N.L.Sarda', 'rnls@iitdh.ac.in'),
(4, 'Prabuchandran K J', 'prabukj@iitdh.ac.in'),
(10, 'Prof. G. Nagaraja', 'prof.gn@iitdh.ac.in'),
(5, 'Rajshekar K', 'rajshekar.k@iitdh.ac.in'),
(6, 'Ramchandra Phawade', 'prb@iitdh.ac.in'),
(14, 'Sagnik Sen', 'sen@iitdh.ac.in'),
(7, 'Sandeep R.B', 'sandeeprb@iitdh.ac.in'),
(8, 'Siba Narayan Swain', 'sibaswain@iitdh.ac.in'),
(13, 'Sudhanshu Shukla ', 'sudhanshu@iitdh.ac.in'),
(9, 'Sudheendra Hangal', 'hangal@iitdh.ac.in');

-- --------------------------------------------------------

--
-- Table structure for table `room_table`
--

CREATE TABLE `room_table` (
  `room_no` varchar(50) NOT NULL,
  `capacity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `room_table`
--

INSERT INTO `room_table` (`room_no`, `capacity`) VALUES
('115', 50),
('117', 80),
('119', 80),
('203', 50),
('207', 50),
('21', 50),
('210', 80),
('211', 80),
('215', 50),
('22', 80),
('23', 120),
('lab1', 80),
('lab2', 80),
('lab3', 50),
('lab4', 80),
('lab5', 70),
('lab6', 70),
('lab7', 50);

-- --------------------------------------------------------

--
-- Table structure for table `slot_table`
--

CREATE TABLE `slot_table` (
  `slot_name` varchar(70) NOT NULL,
  `day` varchar(70) NOT NULL,
  `time_from` varchar(70) NOT NULL,
  `till_time` varchar(70) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `slot_table`
--

INSERT INTO `slot_table` (`slot_name`, `day`, `time_from`, `till_time`) VALUES
('S1', 'Monday Tuesday Thursday', '8:30 9:30 10:35', '9:25 10:25 11:30'),
('S10', 'Tuesday Friday ', '2:00 2:00 ', '3:25 3:25 '),
('S11', 'Tuesday Friday ', '3:30 3:30 ', '4:55 4:55 '),
('S12', 'Monday Thursday ', '5:00 5:00 ', '6:25 6:25 '),
('S13', 'Monday Thursday ', '6:30 6:30 ', '7:55 7:55 '),
('S14', 'Tuesday Friday ', '5:00 5:00 ', '6:25 6:25 '),
('S15', 'Tuesday Friday ', '6:30 6:30 ', '7:55 7:55 '),
('S2', 'Monday Tuesday Thursday', '9:30 10:35 11:35', '10:25 11:30 12:30'),
('S3', 'Monday Tuesday Thursday', '10:35 11:35 8:30', '11:30 12:30 9:25'),
('S4', 'Monday Tuesday Thursday', '11:35 8:30 9:30', '12:30 9:25 10:25'),
('S5', 'Wednesday Friday ', '9:30 11:35 ', '10:25 12:30 '),
('S6', 'Wednesday Friday ', '11:35 9:30 ', '12:30 10:25 '),
('S7', 'Wednesday Friday ', '8:30 8:30 ', '9:25 9:25 '),
('S8', 'Monday Thursday ', '2:00 2:00 ', '3:25 3:25 '),
('S9', 'Monday Thursday ', '3:30 3:30 ', '4:55 4:55 ');

-- --------------------------------------------------------

--
-- Table structure for table `user_master`
--

CREATE TABLE `user_master` (
  `UserId` int(11) NOT NULL,
  `UserName` varchar(20) NOT NULL,
  `Password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `user_master`
--

INSERT INTO `user_master` (`UserId`, `UserName`, `Password`) VALUES
(1, 'admin', 'admin123');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`course_name`),
  ADD UNIQUE KEY `course_name` (`course_name`),
  ADD KEY `instructor` (`instructor`),
  ADD KEY `department_code` (`department_code`);

--
-- Indexes for table `course_table`
--
ALTER TABLE `course_table`
  ADD PRIMARY KEY (`course_name`);

--
-- Indexes for table `department`
--
ALTER TABLE `department`
  ADD PRIMARY KEY (`dept_code`);

--
-- Indexes for table `facultyreg`
--
ALTER TABLE `facultyreg`
  ADD PRIMARY KEY (`name`);

--
-- Indexes for table `room_table`
--
ALTER TABLE `room_table`
  ADD PRIMARY KEY (`room_no`);

--
-- Indexes for table `slot_table`
--
ALTER TABLE `slot_table`
  ADD PRIMARY KEY (`slot_name`);

--
-- Indexes for table `user_master`
--
ALTER TABLE `user_master`
  ADD PRIMARY KEY (`UserId`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `user_master`
--
ALTER TABLE `user_master`
  MODIFY `UserId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `course`
--
ALTER TABLE `course`
  ADD CONSTRAINT `course_ibfk_1` FOREIGN KEY (`instructor`) REFERENCES `facultyreg` (`name`),
  ADD CONSTRAINT `course_ibfk_2` FOREIGN KEY (`department_code`) REFERENCES `department` (`dept_code`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
