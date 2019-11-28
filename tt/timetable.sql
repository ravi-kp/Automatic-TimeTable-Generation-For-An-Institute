-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 28, 2019 at 12:02 PM
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
  `course_name` varchar(50) NOT NULL,
  `no_of_student` varchar(50) NOT NULL,
  `sem_type` varchar(40) NOT NULL,
  `semester` varchar(50) NOT NULL,
  `department` varchar(50) NOT NULL,
  `lab` varchar(10) NOT NULL,
  `preference` varchar(40) NOT NULL,
  `preffered_room` varchar(50) DEFAULT NULL,
  `preffered_slot` varchar(50) NOT NULL,
  `division` varchar(50) NOT NULL,
  `lab_room` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `course`
--

INSERT INTO `course` (`course_name`, `no_of_student`, `sem_type`, `semester`, `department`, `lab`, `preference`, `preffered_room`, `preffered_slot`, `division`, `lab_room`) VALUES
('Chemistry_lab ', '40', 'odd', '1', 'CSE', 'y', '0', '', '', 'D1', 'Chemistry_Lab NULL NULL'),
('Chemistry_lab ', '40', 'odd', '1', 'CSE', 'y', '1', 'Chemistry_Lab', 'L4', 'D2', 'Chemistry_Lab NULL NULL'),
('Chemistry_lab ', '40', 'odd', '1', 'CSE', 'y', '0', '', '', 'D3', 'Chemistry_Lab NULL NULL'),
('Calculus ', '120', 'odd', '1', 'CSE', 'n', '0', '', '', '', ''),
('Quantum_physics_and_Applications', '120', 'odd', '1', 'CSE', 'n', '0', '', '', '', ''),
('Engineering_Graphics_lab_(Lab_session)', '40', 'odd', '1', 'CSE', 'y', '0', '', '', 'D1', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Engineering_Graphics_lab_(Lab_session)', '40', 'odd', '1', 'CSE', 'y', '0', '', '', 'D2', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Engineering_Graphics_lab_(Lab_session)', '40', 'odd', '1', 'CSE', 'y', '0', '', '', 'D3', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Engineering_Lab ', '40', 'odd', '1', 'CSE', 'y', '0', '', '', 'D1', 'Mech_Workshop NULL NULL'),
('Engineering_Lab ', '40', 'odd', '1', 'CSE', 'y', '0', '', '', 'D2', 'Mech_Workshop NULL NULL'),
('Engineering_Lab ', '40', 'odd', '1', 'CSE', 'y', '0', '', '', 'D3', 'Mech_Workshop NULL NULL'),
('Data_Structures_and_Algorithms', '50', 'odd', '3', 'CSE', 'n', '0', '', '', '', ''),
('Discrete_Structures', '50', 'odd', '3', 'CSE', 'n', '0', '', '', '', ''),
('Data_Structures_and_Algorithms_Lab', '50', 'odd', '3', 'CSE', 'y', '0', '', '', 'D1', 'Computer_LabII NULL NULL'),
('Software_Systems_Lab', '50', 'odd', '1', 'CSE', 'y', '0', '', '', 'D1', 'Computer_LabII NULL NULL'),
('Electronic_devices ', '50', 'odd', '3', 'EE', 'n', '0', '', '', '', ''),
('Network_theory ', '50', 'odd', '3', 'EE', 'n', '0', '', '', '', ''),
('Signals_and_Systems', '50', 'odd', '3', 'EE', 'n', '0', '', '', '', ''),
('Complex_Analysis', '50', 'odd', '3', 'EE', 'n', '0', '', '', '', ''),
('Differential_equations_II', '50', 'odd', '3', 'CSE', 'n', '0', '', '', '', ''),
('Engineering_Mechanics', '50', 'odd', '3', 'ME', 'n', '0', '', '', '', ''),
('Engineering_Materials', '50', 'odd', '3', 'ME', 'n', '0', '', '', '', ''),
('Thermodynamics', '50', 'odd', '3', 'ME', 'n', '0', '', '', '', ''),
('Machine_Drawing_and_3D_Modelling ', '50', 'odd', '3', 'ME', 'y', '0', '', '', 'D1', 'Computer_Lab(Ground_Floor) NULL NULL'),
('Introduction_to_Literature_Philosophy', '80', 'odd', '5', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Computer_Architecture ', '75', 'odd', '5', 'CSE,EE', 'n', '0', '', '', '', ''),
('Data_Bases_and_Information_Systems', '40', 'odd', '5', 'CSE', 'n', '0', '', '', '', ''),
('Elementary_Algebra_and_Number_Theory', '40', 'odd', '5', 'CSE', 'n', '0', '', '', '', ''),
('Probability_and_Random_Processes', '60', 'odd', '5', 'CSE,EE', 'n', '0', '', '', '', ''),
('Pattern_recognition_and_machine_learning', '60', 'odd', '57', 'CSE,EE', 'n', '0', '', '', '', ''),
('Graph_theory_and_combinatorics', '40', 'odd', '57', 'CSE', 'n', '0', '', '', '', ''),
('Data_Bases_and_Information_Systems_Lab', '40', 'odd', '5', 'CSE', 'y', '0', '', '', 'D1', 'Computer_LabII NULL NULL'),
('Digital_Systems_Lab', '40', 'odd', '5', 'CSE,EE', 'y', '0', '', '', 'D1', 'Micro_Electronics_Lab NULL NULL'),
('Digital_Systems_Lab', '40', 'odd', '5', 'CSE,EE', 'y', '0', '', '', 'D2', 'Micro_Electronics_Lab NULL NULL'),
('Computer_Architecture_Lab', '40', 'odd', '5', 'CSE,EE', 'y', '0', '', '', 'D1', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Computer_Architecture_Lab', '40', 'odd', '5', 'CSE,EE', 'y', '0', '', '', 'D2', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Distributed_Systems ', '40', 'odd', '7', 'CSE', 'n', '0', '', '', '', ''),
('Reinforcement_learning ', '50', 'odd', '7', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Astrophysics_for_Engineers ', '40', 'odd', '7', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Statistical_Mechanics', '40', 'odd', '7', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Basics_of_Accounting_&_Financial_Management', '40', 'odd', '7', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Technological_entrepreneurship ', '40', 'odd', '7', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Finite_Element_Analysis', '40', 'odd', '7', 'ME', 'n', '0', '', '', '', ''),
('Vibrations_of_Linear_Systems', '40', 'odd', '7', 'ME', 'n', '0', '', '', '', ''),
('Introduction_to_Combustion', '40', 'odd', '7', 'ME', 'n', '0', '', '', '', ''),
('Power_system_dynamics_and-control', '40', 'odd', '7', 'EE', 'n', '0', '', '', '', ''),
('Wireless_communication', '40', 'odd', '7', 'EE', 'n', '0', '', '', '', ''),
('VLSI_Design', '40', 'odd', '7', 'EE', 'n', '0', '', '', '', ''),
('Control_systems ', '70', 'odd', '5', 'ME,EE', 'n', '0', '', '', '', ''),
('Power_Systems', '40', 'odd', '5', 'EE', 'n', '0', '', '', '', ''),
('Analog_Circuits_Lab', '40', 'odd', '5', 'EE', 'y', '0', '', '', 'D1', 'Micro_Electronics_Lab NULL NULL'),
('Heat_Transfer', '40', 'odd', '5', 'ME', 'n', '0', '', '', '', ''),
('Kinematics_and-Dynamics_of_Machines', '40', 'odd', '5', 'ME', 'n', '0', '', '', '', ''),
('Manufacturing_Processes_II', '40', 'odd', '5', 'ME', 'n', '0', '', '', '', ''),
('Communications_Lab ', '40', 'odd', '7', 'EE', 'y', '0', '', '', 'D1', 'DSP/PE_Lab NULL NULL'),
('Manufacturing_Processes_Lab ', '40', 'odd', '7', 'ME', 'y', '0', '', '', 'D1', 'Manufacturing_Lab NULL NULL'),
('Essential_biology	', '120', 'even', '2', 'CSE', 'n', '0', '', '', '', ''),
('Computer_programming	', '120', 'even', '2', 'CSE', 'n', '0', '', '', '', ''),
('Introduction_to_electrical_system	', '120', 'even', '2', 'CSE', 'n', '0', '', '', '', ''),
('Linear_Algebra	', '120', 'even', '2', 'CSE', 'n', '0', '', '', '', ''),
('Differential_Equation_I	', '120', 'even', '2', 'CSE', 'n', '0', '', '', '', ''),
('Electricity_and_Magnetism	', '120', 'even', '2', 'CSE', 'n', '0', '', '', '', ''),
('Introduction_to_electrical_system_Lab	', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D1', 'Micro_Electronics_Lab NULL NULL'),
('Introduction_to_electrical_system_Lab	', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D2', 'Micro_Electronics_Lab NULL NULL'),
('Introduction_to_electrical_system_Lab	', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D3', 'Micro_Electronics_Lab NULL NULL'),
('Physics_Lab', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D1', 'Physics_Lab NULL NULL'),
('Physics_Lab', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D2', 'Physics_Lab NULL NULL'),
('Physics_Lab', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D3', 'Physics_Lab NULL NULL'),
('Essential_biology_Lab	', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D1', 'Chemistry_Lab NULL NULL'),
('Essential_biology_Lab	', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D2', 'Chemistry_Lab NULL NULL'),
('Essential_biology_Lab	', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D3', 'Chemistry_Lab NULL NULL'),
('Computer_Programming_Lab	', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D1', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Computer_Programming_Lab	', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D2', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Computer_Programming_Lab	', '40', 'even', '2', 'CSE', 'y', '0', '', '', 'D3', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Fluid_Mechanics_II', '50', 'even', '4', 'ME', 'n', '0', '', '', '', ''),
('Manufacturing_Process_I', '50', 'even', '4', 'ME', 'n', '0', '', '', '', ''),
('Mechanics_of_Materials', '50', 'even', '4', 'ME', 'n', '0', '', '', '', ''),
('Numerical-Analysis', '40', 'even', '4', 'ME', 'n', '0', '', '', '', ''),
('Control_Systems', '80', 'even', '4', 'ME,EE', 'n', '0', '', '', '', ''),
('Intro_to_analog_ckt_&_probability', '50', 'even', '4', 'EE', 'n', '0', '', '', '', ''),
('Intro_to_electrical_machine_power_electronics', '50', 'even', '4', 'EE', 'n', '0', '', '', '', ''),
('electromagnetics_and_intro_to_power_system', '50', 'even', '4', 'EE', 'n', '0', '', '', '', ''),
('Devices_and_Circuits_Lab', '50', 'even', '4', 'EE', 'y', '0', '', '', 'D1', 'Micro_Electronics_Lab NULL NULL'),
('Digital_Systems', '80', 'even', '4', 'CSE,EE', 'n', '0', '', '', '', ''),
('Digital_System_Lab', '40', 'even', '4', 'CSE,EE', 'y', '0', '', '', 'D1', 'Micro_Electronics_Lab NULL NULL'),
('Digital_System_Lab', '40', 'even', '4', 'CSE,EE', 'y', '0', '', '', 'D2', 'Micro_Electronics_Lab NULL NULL'),
('Design_and_Analysis_of_Algo', '40', 'even', '4', 'CSE', 'n', '0', '', '', '', ''),
('Computer_Network', '40', 'even', '4', 'CSE', 'n', '0', '', '', '', ''),
('Automata_Theory', '40', 'even', '4', 'CSE', 'n', '0', '', '', '', ''),
('Computer_Network_Lab', '40', 'even', '4', 'CSE', 'y', '0', '', '', 'D1', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Applied_Thermodynamics', '40', 'even', '6', 'ME', 'n', '0', '', '', '', ''),
('Machine_Design', '40', 'even', '6', 'ME', 'n', '0', '', '', '', ''),
('Manufacturing_Processes_Lab', '40', 'even', '6', 'ME', 'y', '0', '', '', 'D1', 'Manufacturing_Lab NULL NULL'),
('Heat_Transfer_Lab', '40', 'even', '6', 'ME', 'y', '0', '', '', 'D1', 'Heat_Transfer_Lab NULL NULL'),
('KDOM_Lab', '40', 'even', '6', 'ME', 'y', '0', '', '', 'D1', 'KDOM_Lab NULL NULL'),
('Artificial_Intelligence', '40', 'odd', '6', 'CSE', 'n', '0', '', '', '', ''),
('Operating_System', '40', 'even', '6', 'CSE', 'n', '0', '', '', '', ''),
('Software_Engineering', '40', 'even', '6', 'CSE', 'n', '0', '', '', '', ''),
('Artificial_Intelligence_Lab', '40', 'even', '6', 'CSE', 'y', '0', '', '', 'D1', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Operating_System_Lab', '40', 'even', '6', 'CSE', 'y', '0', '', '', 'D1', 'Computer_Lab(Ground_Floor) Computer_LabII NULL'),
('Data_Analysis', '40', 'even', '6', 'EE', 'n', '0', '', '', '', ''),
('Electronic_Devices', '40', 'even', '6', 'EE', 'n', '0', '', '', '', ''),
('DSP_Lab', '40', 'even', '6', 'EE', 'y', '0', '', '', 'D1', 'DSP/PE_Lab NULL NULL'),
('Electronics_Devices_Lab', '40', 'even', '6', 'EE', 'y', '0', '', '', 'D1', 'Micro_Electronics_Lab NULL NULL'),
('Composite_Materials', '40', 'even', '68', 'ME', 'n', '0', '', '', '', ''),
('Theory_of_Elasticity', '40', 'even', '68', 'ME', 'n', '0', '', '', '', ''),
('Turbomachinery', '40', 'even', '68', 'ME', 'n', '0', '', '', '', ''),
('Advanced_FEM', '40', 'even', '8', 'ME', 'n', '0', '', '', '', ''),
('Compilers', '40', 'even', '68', 'CSE', 'n', '0', '', '', '', ''),
('Parameterized_Algo_and_Complexity', '40', 'even', '68', 'CSE', 'n', '0', '', '', '', ''),
('Statistical_Pattern_Recognition', '50', 'even', '68', 'CSE,EE', 'n', '0', '', '', '', ''),
('information_theory', '50', 'even', '68', 'EE', 'n', '0', '', '', '', ''),
('multivariable_control', '50', 'even', '68', 'EE', 'n', '0', '', '', '', ''),
('speech_processing', '50', 'even', '68', 'EE', 'n', '0', '', '', '', ''),
('Robotics', '50', 'even', '8', 'ME', 'n', '0', '', '', '', ''),
('Artificial_Neural_Networks_Deep_Learning', '40', 'even', '68', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('classical_mechanics', '40', 'even', '68', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Quantum_info,communication,computation', '40', 'even', '8', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Environmental_Studies', '50', 'even', '6', 'CSE,ME,EE', 'n', '1', '23', 'S14', '', ''),
('Data_Analysis', '120', 'odd', '3', 'CSE,ME,EE', 'n', '1', '23', 'S12', '', ''),
('Engineering_Graphics', '120', 'odd', '1', 'CSE', 'n', '0', '', '', '', ''),
('Economics', '120', 'odd', '3', 'CSE,ME,EE', 'n', '1', '23', 'S14', '', ''),
('Control_System_Lab', '80', 'even', '4', 'ME,EE', 'y', '0', '', '', 'D1', 'DSP/PE_Lab DSP/PE_Lab NULL'),
('Control_System_Lab', '60', 'odd', '5', 'ME,EE', 'y', '0', '', '', 'D1', 'DSP/PE_Lab NULL NULL'),
('Solid_Mechanics_Lab', '40', 'odd', '5', 'ME', 'y', '0', '', '', 'D1', 'Solid_Mechanics_Lab NULL NULL'),
('Mechanical_Measurements_Lab', '40', 'odd', '5', 'ME', 'y', '0', '', '', 'D1', 'Measurement_Lab NULL NULL'),
('Chemistry', '120', 'odd', '1', 'CSE', 'n', '0', '', '', '', ''),
('Elements_of_3D_Modeling', '50', 'even', '68', 'ME', 'n', '0', '', '', '', ''),
('Power_Elecrtonics_Lab', '40', 'odd', '5', 'EE', 'y', '0', '', '', 'D1', 'Machine_Lab NULL NULL'),
('Sustainable_energy_and_energy_matetials', '40', 'even', '8', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Applied_Ethics', '40', 'even', '8', 'CSE,ME,EE', 'n', '0', '', '', '', ''),
('Modernism_its_heroic', '40', 'even', '8', 'CSE,ME,EE', 'n', '0', '', '', '', '');

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
('', '1', 0, 'CSE', 'y', 0, '', ''),
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
('Chemistry_Lab', 80),
('Computer_Lab(Ground_Floor)', 80),
('Computer_LabII', 80),
('DSP/PE_Lab', 80),
('Eng_Drawing_Lab', 80),
('Fluid_Mechanics', 80),
('Heat_Transfer_Lab', 80),
('KDOM_Lab', 80),
('Machine_Lab', 80),
('Manufacturing_Lab', 80),
('Measurement_Lab', 80),
('Mech_Workshop', 80),
('Micro_Electronics_Lab', 80),
('Physics_Lab', 80),
('Solid_Mechanics_Lab', 80),
('SOM_Lab', 80);

-- --------------------------------------------------------

--
-- Table structure for table `slot_table`
--

CREATE TABLE `slot_table` (
  `slot_id` int(11) NOT NULL,
  `slot_name` varchar(70) NOT NULL,
  `day` varchar(70) NOT NULL,
  `time_from` varchar(70) NOT NULL,
  `till_time` varchar(70) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `slot_table`
--

INSERT INTO `slot_table` (`slot_id`, `slot_name`, `day`, `time_from`, `till_time`) VALUES
(1, 'S1', 'Monday Tuesday Thursday', '8:30 9:30 10:35', '9:25 10:25 11:30'),
(2, 'S2', 'Monday Tuesday Thursday', '9:30 10:35 11:35', '10:25 11:30 12:30'),
(3, 'S3', 'Monday Tuesday Thursday', '10:35 11:35 8:30', '11:30 12:30 9:25'),
(4, 'S4', 'Monday Tuesday Thursday', '11:35 8:30 9:30', '12:30 9:25 10:25'),
(5, 'S5', 'Wednesday Friday ', '9:30 11:35 ', '10:25 12:30 '),
(6, 'S6', 'Wednesday Friday ', '11:35 9:30 ', '12:30 10:25 '),
(7, 'S7', 'Wednesday Friday ', '8:30 8:30 ', '9:25 9:25 '),
(8, 'S8', 'Monday Thursday ', '2:00 2:00 ', '3:25 3:25 '),
(9, 'S9', 'Monday Thursday ', '3:30 3:30 ', '4:55 4:55 '),
(10, 'S10', 'Tuesday Friday ', '2:00 2:00 ', '3:25 3:25 '),
(11, 'S11', 'Tuesday Friday ', '3:30 3:30 ', '4:55 4:55 '),
(12, 'S12', 'Monday Thursday ', '5:00 5:00 ', '6:25 6:25 '),
(13, 'S13', 'Monday Thursday ', '6:30 6:30 ', '7:55 7:55 '),
(14, 'S14', 'Tuesday Friday ', '5:00 5:00 ', '6:25 6:25 '),
(15, 'S15', 'Tuesday Friday ', '6:30 6:30 ', '7:55 7:55 ');

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
  ADD PRIMARY KEY (`slot_id`);

--
-- Indexes for table `user_master`
--
ALTER TABLE `user_master`
  ADD PRIMARY KEY (`UserId`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `slot_table`
--
ALTER TABLE `slot_table`
  MODIFY `slot_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT for table `user_master`
--
ALTER TABLE `user_master`
  MODIFY `UserId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
