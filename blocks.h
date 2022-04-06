//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	      /*Command*/		                                                                          /*Update Interval*/	/*Update Signal*/
  {"Vol:",        "amixer get Master | awk -F'[][]' '/dB/ {print $2}'",                                   0,                  10},
  {"Brightness:", "brightnessctl -m | awk -F, '{print substr($4, 0, length($4))}'",                       0,                  11},
  {"Bat0:",       "acpi | grep -o '[^ ]*%' | tail -1",                                                    30,                 0},
  {"Bat1:",       "acpi | grep -o '[^ ]*%'",                                                              30,                 0},
  {"Cpu:",        "mpstat 1 1 | grep -A 5 \"%idle\" | tail -n 1 | awk -F \" \" '{print 100 - $12\"%\"}' | awk '{while(length<7) $0=$0 \" \"}1'", 5,                  0},
	{"",            "date '+%b %d %I:%M%p '",					                                                      5,		              0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
