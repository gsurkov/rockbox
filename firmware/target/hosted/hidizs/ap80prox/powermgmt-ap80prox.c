// TODO: figure out the proper values

unsigned short battery_level_disksafe = 3470;

/* the OF shuts down at this voltage */
unsigned short battery_level_shutoff = 3400;

/* voltages (millivolt) of 0%, 10%, ... 100% when charging disabled */
unsigned short percent_to_volt_discharge[11] =
{
    3400, 3477, 3554, 3631, 3708, 3785, 3862, 3939, 4016, 4093, 4170
};

/* voltages (millivolt) of 0%, 10%, ... 100% when charging enabled */
unsigned short percent_to_volt_charge[11] =
{
    3485, 3554, 3622, 3691, 3759, 3828, 3896, 3965, 4033, 4102, 4170
};
