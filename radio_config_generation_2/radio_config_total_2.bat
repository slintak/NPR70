@echo off
for %%M in (11 12 13 14 20 21 22 23 24) do (
	echo .
	echo *********
	echo CONFIG %%M 70cm
	echo *********
	
	
	del SI4463_which_config.h
	(echo #define which_modulation %%M) >> SI4463_which_config.h
	(echo #define which_band "") >> SI4463_which_config.h
	(echo #include "./SI4463_70cm/radio_config_Si4463_%%M.h") >> SI4463_which_config.h
	cl /clr radio_config_generation.cpp
	radio_config_generation.exe
)

for %%M in (11 12 13 14 20 21 22 23 24) do (
	echo .
	echo *********
	echo CONFIG %%M 2m
	echo *********
	
	
	del SI4463_which_config.h
	(echo #define which_modulation %%M) >> SI4463_which_config.h
	(echo #define which_band "_2m") >> SI4463_which_config.h
	(echo #include "./SI4463_2m/radio_config_Si4463_%%M.h") >> SI4463_which_config.h
	cl /clr radio_config_generation.cpp
	radio_config_generation.exe
)

