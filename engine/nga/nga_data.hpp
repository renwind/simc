#pragma once

#include "../util/static_map.hpp"
#include <sstream>
#include <map>

struct nga_table_data_format
{
	const char* value;
	unsigned width;
};

<<<<<<< HEAD
static const std::array<nga_table_data_format, 8> __nga_spell_data_format{ {
	{"", 0},
	{"技能", 0},
	{"图标", 0},
=======
static const std::array<nga_table_data_format, 7> __nga_spell_data_format{ {
	{"", 0},
	{"技能", 0},
>>>>>>> nga/zh_CN
	{"类型", 0},
	{"法强系数", 0},
	{"施法时间", 0},
	{"冷却", 0},
	{"描述", 50},
} };

static constexpr auto __nga_elemental_common_spellid_map = util::make_static_map<unsigned, util::string_view>({
	{196840, "冰霜震击"},
	{188389, "烈焰震击"},
	{188196, "闪电箭"},
	{188443, "闪电链"},
	{285452, "熔岩爆裂"},
	{61882, "地震术"},
	{8042, "大地震击"},
	{60188, "元素之怒"},
	{190493, "怒雷"},
	} );

<<<<<<< HEAD
static constexpr auto __nga_enhance_common_spellid_map = util::make_static_map<unsigned, util::string_view>({
	{33757, "风怒武器"},
	{17364, "风暴打击"},
	{187874, "毁灭闪电"},
	{187880, "漩涡武器"},
	{60103, "熔岩猛击"},
	{51533, "野性狼魂"},
	{334046, "鞭笞烈焰"},
	{8512, "风怒图腾"},
	{334308, "闪电链（等级2）"},
	{201845, "风暴使者"},
	{334175, "风暴怒火"},
	{77223, "精通：增强元素"},
	{58875, "幽魂步"},
	});


=======
>>>>>>> nga/zh_CN
static constexpr auto __nga_force_spellid_map = util::make_static_map<unsigned, util::string_view>({
	{324386, "暮钟图腾(格里恩)"},
	{324520, "暮钟图腾伤害"},
	{324522, "暮钟图腾治疗"},
	{326059, "始源之潮(通灵领主)"},
	{327162, "始源之潮伤害"},
	{327163, "始源之潮治疗"},
	{328923, "法夜输灵(法夜)"},
	{328928, "法夜输灵伤害"},
	{320674, "收割链(温西尔)"},
	{320752, "收割链伤害"},
	{320751, "收割链治疗"},
	});

enum eNgaColor
{
	nc_skyblue = 0,
	nc_royalblue,
	nc_blue,
	nc_darkblue,
	nc_orange,
	nc_orangered,
	nc_crimson,
	nc_red,
	nc_firebrick,
	nc_darkred,
	nc_green,
	nc_limegreen,
	nc_seagreen,
	nc_teal,
	nc_deeppink,
	nc_tomato,
	nc_coral,
	nc_purple,
	nc_indigo,
	nc_burlywood,
	nc_sandybrown,
	nc_chocolate,
	nc_sienna,
	nc_silver,
	nc_black,
};

static constexpr auto _nga_color_map = util::make_static_map<unsigned, util::string_view>({
  { 0, "skyblue" },
  { 1, "royalblue" },
  { 2, "blue" },
  { 3, "darkblue" },
  { 4, "orange" },
  { 5, "orangered" },
  { 6, "crimson" },
  { 7, "red" },
  { 8, "firebrick" },
  { 9, "darkred" },
  { 10, "green" },
  { 11, "limegreen" },
  { 12, "seagreen" },
  { 13, "teal" },
  { 14, "deeppink" },
  { 15, "tomato" },
  { 16, "coral" },
  { 17, "purple" },
  { 18, "indigo" },
  { 19, "burlywood" },
  { 20, "sandybrown" },
  { 21, "chocolate" },
  { 22, "sienna" },
  { 23, "silver" },
  { 24, "black" },
	});

const char* nga_school_type_string(school_e school);


const eNgaColor nga_school_type_color(school_e school);
// support function
std::string nga_number(double value);

std::string nga_tr(std::string value);

std::string nga_td(std::string value, unsigned width = 0);

std::string nga_b(std::string value);
std::string nga_color(std::string value, eNgaColor c);

std::string nga_align_center(std::string value);

<<<<<<< HEAD
std::string nga_to_skill_table(const dbc_t& dbc, unsigned shaman_type);
std::string nga_to_conduit_table(const dbc_t& dbc);
std::string nga_to_lengendary_table(const dbc_t& dbc)
=======
std::string to_nga_table(const dbc_t& dbc);
>>>>>>> nga/zh_CN
