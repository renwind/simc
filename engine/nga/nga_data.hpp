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
	{"����", 0},
	{"ͼ��", 0},
=======
static const std::array<nga_table_data_format, 7> __nga_spell_data_format{ {
	{"", 0},
	{"����", 0},
>>>>>>> nga/zh_CN
	{"����", 0},
	{"��ǿϵ��", 0},
	{"ʩ��ʱ��", 0},
	{"��ȴ", 0},
	{"����", 50},
} };

static constexpr auto __nga_elemental_common_spellid_map = util::make_static_map<unsigned, util::string_view>({
	{196840, "��˪���"},
	{188389, "�������"},
	{188196, "�����"},
	{188443, "������"},
	{285452, "���ұ���"},
	{61882, "������"},
	{8042, "������"},
	{60188, "Ԫ��֮ŭ"},
	{190493, "ŭ��"},
	} );

<<<<<<< HEAD
static constexpr auto __nga_enhance_common_spellid_map = util::make_static_map<unsigned, util::string_view>({
	{33757, "��ŭ����"},
	{17364, "�籩���"},
	{187874, "��������"},
	{187880, "��������"},
	{60103, "�����ͻ�"},
	{51533, "Ұ���ǻ�"},
	{334046, "��������"},
	{8512, "��ŭͼ��"},
	{334308, "���������ȼ�2��"},
	{201845, "�籩ʹ��"},
	{334175, "�籩ŭ��"},
	{77223, "��ͨ����ǿԪ��"},
	{58875, "�Ļ경"},
	});


=======
>>>>>>> nga/zh_CN
static constexpr auto __nga_force_spellid_map = util::make_static_map<unsigned, util::string_view>({
	{324386, "ĺ��ͼ��(�����)"},
	{324520, "ĺ��ͼ���˺�"},
	{324522, "ĺ��ͼ������"},
	{326059, "ʼԴ֮��(ͨ������)"},
	{327162, "ʼԴ֮���˺�"},
	{327163, "ʼԴ֮������"},
	{328923, "��ҹ����(��ҹ)"},
	{328928, "��ҹ�����˺�"},
	{320674, "�ո���(������)"},
	{320752, "�ո����˺�"},
	{320751, "�ո�������"},
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
