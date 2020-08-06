#include "simulationcraft.hpp"
#include "sim/sc_sim.hpp"
#include "nga_data.hpp"
<<<<<<< HEAD
#include "../dbc/covenant_data.hpp"
#include "../util/static_map.hpp"
#include "../interfaces/sc_http.hpp"
=======
>>>>>>> nga/zh_CN


const char* nga_school_type_string(school_e school)
{
	switch (school)
	{
	case SCHOOL_ASTRAL:           return "astral";
	case SCHOOL_ARCANE:           return "奥术";
	case SCHOOL_CHAOS:            return "chaos";
	case SCHOOL_FIRE:             return "火焰";
	case SCHOOL_FROST:            return "冰霜";
	case SCHOOL_FROSTFIRE:        return "frostfire";
	case SCHOOL_HOLY:             return "holy";
	case SCHOOL_NATURE:           return "自然";
	case SCHOOL_PHYSICAL:         return "物理";
	case SCHOOL_SHADOW:           return "暗影";
	case SCHOOL_HOLYSTRIKE:       return "holystrike";
	case SCHOOL_FLAMESTRIKE:      return "flamestrike";
	case SCHOOL_HOLYFIRE:         return "holyfire";
	case SCHOOL_STORMSTRIKE:      return "stormstrike";
	case SCHOOL_HOLYSTORM:        return "holystorm";
	case SCHOOL_FIRESTORM:        return "firestorm";
	case SCHOOL_FROSTSTRIKE:      return "froststrike";
	case SCHOOL_HOLYFROST:        return "holyfrost";
	case SCHOOL_FROSTSTORM:       return "froststorm";
	case SCHOOL_SHADOWSTRIKE:     return "shadowstrike";
	case SCHOOL_SHADOWLIGHT:      return "shadowlight";
	case SCHOOL_SHADOWFLAME:      return "shadowflame";
	case SCHOOL_SHADOWSTORM:      return "shadowstorm";
	case SCHOOL_SHADOWFROST:      return "shadowfrost";
	case SCHOOL_SPELLSTRIKE:      return "spellstrike";
	case SCHOOL_DIVINE:           return "divine";
	case SCHOOL_SPELLFIRE:        return "spellfire";
	case SCHOOL_SPELLFROST:       return "spellfrost";
	case SCHOOL_SPELLSHADOW:      return "spellshadow";
	case SCHOOL_ELEMENTAL:        return "元素";
	case SCHOOL_CHROMATIC:        return "chromatic";
	case SCHOOL_MAGIC:            return "magic";
	case SCHOOL_DRAIN:            return "drain";
	case SCHOOL_NONE:             return "none";
	default:                      return "未知";
	}
}


const eNgaColor nga_school_type_color(school_e school)
{
	switch (school)
	{
	case SCHOOL_FIRE:             return nc_red;
	case SCHOOL_FROST:            return nc_blue;
	case SCHOOL_SHADOW:           return nc_indigo;
	case SCHOOL_ARCANE:           return nc_purple;
	case SCHOOL_NATURE:           return nc_green;
	case SCHOOL_PHYSICAL:         return nc_burlywood;
	case SCHOOL_ELEMENTAL:        return nc_deeppink;
	default:                      return nc_indigo;
	}
}


<<<<<<< HEAD

std::string nga_icon_url(unsigned value)
{
	std::string result;
	if (http::get(result, "http://shadowlands.wowhead.com/icon=" + std::to_string(value), cache::CURRENT))
	{
		std::string strKey = ".jpg";
		auto iconUrlKey = result.find(strKey);
		auto iconUrlEnd = result.find("\"", iconUrlKey);
		auto iconUrlBegin = result.rfind("\"", iconUrlKey) + 1;
		auto iconUrl = result.substr(iconUrlBegin, iconUrlEnd - iconUrlBegin);
		return iconUrl;
	}
	return "";
}

std::string nga_img(std::string value)
{
	std::ostringstream s;
	s << "[img]" << value << "[/img]";

	return s.str();
}

=======
>>>>>>> nga/zh_CN
// support function
std::string nga_number(double value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}


std::string nga_tr(std::string value)
{
	std::ostringstream s;
	s << "[tr]" << std::endl;
	s << value;
	s << "[/tr]" << std::endl;

	return s.str();
}

std::string nga_td(std::string value, unsigned width)
{
	std::ostringstream s;
	if (width > 0)
		s << "[td" << width << "]";
	else
		s << "[td]";
	s << value << "[/td]" << std::endl;
	return s.str();
}


std::string nga_b(std::string value)
{
	std::ostringstream s;
	s << "[b]" << value << "[/b]";
	return s.str();
}

std::string nga_color(std::string value, eNgaColor c)
{
	std::ostringstream s;
	auto i = _nga_color_map.find(c);
	if (i != _nga_color_map.end())
	{
		s << "[color=" << i->second.data() << "]" << value << "[/color]";
		return s.str();
	}

	s << value;
	return s.str();
}

<<<<<<< HEAD
std::string nga_font(std::string value)
{
	std::ostringstream s;
	s << "[font=Comic Sans MS]" << value << "[/font]";
	return s.str();
}



=======
>>>>>>> nga/zh_CN
std::string nga_align_center(std::string value)
{
	std::ostringstream s;
	s << "[align = center]";
	s << value;
	s << "[/align]";

	return s.str();
}



<<<<<<< HEAD
std::string nga_to_skill_table_row(const dbc_t& dbc, const spell_data_t* spell, unsigned shaman_type, int level, std::string rowspan = "")
=======
std::string to_nga_table_row(const dbc_t& dbc, const spell_data_t* spell, int level, std::string rowspan = "")
>>>>>>> nga/zh_CN
{

	std::ostringstream s;
	s << "[tr]" << std::endl;

	s << rowspan;

	const spelltext_data_t& spell_text = dbc.spell_text(spell->id());
	const spelldesc_vars_data_t& spelldesc_vars = dbc.spell_desc_vars(spell->id());

<<<<<<< HEAD
	// Name
	std::string name_str = spell->name_cstr();
	auto force_spell = __nga_force_spellid_map.find(spell->id());
	if (force_spell != __nga_force_spellid_map.end())
		name_str = force_spell->second.data();
	if (shaman_type == 0)
	{
		auto s = __nga_elemental_common_spellid_map.find(spell->id());
		if (s != __nga_elemental_common_spellid_map.end())
			name_str = s->second.data();
	}
	else if (shaman_type == 1)
	{
		auto s = __nga_enhance_common_spellid_map.find(spell->id());
		if (s != __nga_enhance_common_spellid_map.end())
			name_str = s->second.data();
	}
	s << nga_td(nga_align_center(name_str));

	// Icon image
	auto icon_url = nga_icon_url(spell->_icon_id);
	s << nga_td(nga_align_center(nga_img(icon_url)));

=======
	std::string name_str = spell->name_cstr();
	auto ele_spell = __nga_elemental_common_spellid_map.find(spell->id());
	if (ele_spell != __nga_elemental_common_spellid_map.end())
		name_str = ele_spell->second.data();
	else
	{
		auto force_spell = __nga_force_spellid_map.find(spell->id());
		if (force_spell != __nga_force_spellid_map.end())
			name_str = force_spell->second.data();
	}
	s << nga_td(nga_align_center(name_str));

>>>>>>> nga/zh_CN
	// School
	std::string school_string = nga_school_type_string(spell->get_school_type());
	s << nga_td(nga_align_center(nga_color(school_string, nga_school_type_color(spell->get_school_type()))));

	// sp/ap coefficient
	double max_coeff = 0;
	for (const spelleffect_data_t& e : spell->effects())
	{
		if (e.id() == 0)
			continue;

		max_coeff = std::max(max_coeff, std::max(e.sp_coeff(), e.ap_coeff()));
	}
	std::string coeff_string;
	if (max_coeff > 0)
		coeff_string = nga_number(max_coeff);
	else
		coeff_string = "-";
	s << nga_td(nga_align_center(coeff_string));

	// Cast Time
	std::string cast_string;
	if (spell->cast_time() > 0_ms)
		cast_string = nga_number(spell->cast_time().total_seconds()) + "s";
	else
		cast_string = "瞬发";
	s << nga_td(nga_align_center(cast_string));

	// GCD
	//std::string gcd_string;
	//if (spell->gcd() != timespan_t::zero())
	//	gcd_string = nga_number(spell->gcd().total_seconds()) + "s";
	//s << nga_td(gcd_string);

	// Cooldown
	std::string cooldown_string;
	if (spell->cooldown() > timespan_t::zero())
		cooldown_string = nga_number(spell->cooldown().total_seconds()) + "s";
	else
		cooldown_string = "-";
	s << nga_td(nga_align_center(cooldown_string));


	// Range
	//std::string range_string;
	//if (spell->min_range() || spell->max_range())
	//{
	//	if (spell->min_range())
	//		range_string += std::to_string((int)spell->min_range()) + " - ";

	//	range_string += std::to_string((int)spell->max_range()) + " 码";
	//}
	//else
	//	range_string = "-";
	//	s << nga_td(range_string);



	if (spell_text.desc())
		s << nga_td(spell_text.desc());
	else
		s << nga_td("");

	s << "[/tr]" << std::endl;


	return s.str();
}




<<<<<<< HEAD
std::string nga_to_skill_table(const dbc_t& dbc, unsigned shaman_type)
=======
std::string to_nga_table(const dbc_t& dbc)
>>>>>>> nga/zh_CN
{
	std::ostringstream s;
	s << "[table]" << std::endl;

	// first row
	std::ostringstream sr;
	util::span<const nga_table_data_format> ngaData = ::util::make_span(__nga_spell_data_format);
	for (auto data : ngaData)
	{
		sr << nga_td(nga_align_center(nga_b(data.value)), data.width);
	}
	s << nga_tr(sr.str());

	//int common_spell_number = 0;
	std::vector< const spell_data_t *> common_spell_vector;
	std::vector< const spell_data_t *> force_spell_vector;
	for (const spell_data_t &spell : spell_data_t::data())
	{
		if (spell.class_mask() && spell.is_class(player_e::SHAMAN))
		{
<<<<<<< HEAD
			if (shaman_type == 0)
			{
				if (__nga_elemental_common_spellid_map.find(spell.id()) != __nga_elemental_common_spellid_map.end())
					common_spell_vector.push_back(&spell);
			}
			else if (shaman_type == 1)
			{
				if (__nga_enhance_common_spellid_map.find(spell.id()) != __nga_enhance_common_spellid_map.end())
					common_spell_vector.push_back(&spell);
			}
=======
			if (__nga_elemental_common_spellid_map.find(spell.id()) != __nga_elemental_common_spellid_map.end())
				common_spell_vector.push_back(&spell);
>>>>>>> nga/zh_CN
			if (__nga_force_spellid_map.find(spell.id()) != __nga_force_spellid_map.end())
				force_spell_vector.push_back(&spell);
		}
	}

<<<<<<< HEAD
	std::string row_span = "[td rowspan=" + nga_number((double)common_spell_vector.size()) + "]通用[/td]";
=======
	std::string row_span = "[td rowspan=" + nga_number(common_spell_vector.size()) + "]通用[/td]";
>>>>>>> nga/zh_CN
	bool bFirstLine = true;
	for (const spell_data_t *spell : common_spell_vector)
	{
		if (bFirstLine)
		{
<<<<<<< HEAD
			s << nga_to_skill_table_row(dbc, spell, MAX_LEVEL, shaman_type, row_span);
			bFirstLine = false;
		}
		else
			s << nga_to_skill_table_row(dbc, spell, MAX_LEVEL, shaman_type);
	}

	row_span = "[td rowspan=" + nga_number((double)force_spell_vector.size()) + "]盟约[/td]";
=======
			s << to_nga_table_row(dbc, spell, MAX_LEVEL, row_span);
			bFirstLine = false;
		}
		else
			s << to_nga_table_row(dbc, spell, MAX_LEVEL);
	}

	row_span = "[td rowspan=" + nga_number(common_spell_vector.size()) + "]盟约[/td]";
>>>>>>> nga/zh_CN
	bFirstLine = true;
	for (const spell_data_t *spell : force_spell_vector)
	{
		if (bFirstLine)
		{
<<<<<<< HEAD
			s << nga_to_skill_table_row(dbc, spell, MAX_LEVEL, shaman_type, row_span);
			bFirstLine = false;
		}
		else
			s << nga_to_skill_table_row(dbc, spell, MAX_LEVEL, shaman_type);
=======
			s << to_nga_table_row(dbc, spell, MAX_LEVEL, row_span);
			bFirstLine = false;
		}
		else
			s << to_nga_table_row(dbc, spell, MAX_LEVEL);
>>>>>>> nga/zh_CN
	}


	int iTalentCount = 0;
	std::map<int, std::string> talentTreeMap;
	for (const talent_data_t &talent : talent_data_t::data())
	{
		if (talent.is_class(player_e::SHAMAN))
		{
			// common talent
			if (talent.row() * 10 + talent.col() == 40)
			{
				std::string row_span = "[td rowspan=3]T5[/td]";
<<<<<<< HEAD
				talentTreeMap[talent.row() * 10 + talent.col()] = nga_to_skill_table_row(dbc, talent.spell(), MAX_LEVEL, shaman_type, row_span);
			}
			if (talent.row() * 10 + talent.col() == 42)
			{
				talentTreeMap[talent.row() * 10 + talent.col()] = nga_to_skill_table_row(dbc, talent.spell(), MAX_LEVEL, shaman_type);
			}

			// elemental talent
			unsigned masterT = SHAMAN_ELEMENTAL;
			if (shaman_type == 0)
				masterT = SHAMAN_ELEMENTAL;
			else if (shaman_type == 1)
				masterT = SHAMAN_ENHANCEMENT;
			if (talent.spec() == masterT)
=======
				talentTreeMap[talent.row() * 10 + talent.col()] = to_nga_table_row(dbc, talent.spell(), MAX_LEVEL, row_span);
			}
			if (talent.row() * 10 + talent.col() == 42)
			{
				talentTreeMap[talent.row() * 10 + talent.col()] = to_nga_table_row(dbc, talent.spell(), MAX_LEVEL);
			}

			// elemental talent
			if (talent.spec() == SHAMAN_ELEMENTAL)
>>>>>>> nga/zh_CN
			{
				iTalentCount++;
				if (talent.col() == 0)
				{
					int tier = talent.row() + 1;
					std::string row_span = "[td rowspan=3]T" + nga_number(tier) + "[/td]";
<<<<<<< HEAD
					talentTreeMap[talent.row() * 10 + talent.col()] = nga_to_skill_table_row(dbc, talent.spell(), MAX_LEVEL, shaman_type, row_span);
				}
				else
					talentTreeMap[talent.row() * 10 + talent.col()] = nga_to_skill_table_row(dbc, talent.spell(), shaman_type, MAX_LEVEL);
=======
					talentTreeMap[talent.row() * 10 + talent.col()] = to_nga_table_row(dbc, talent.spell(), MAX_LEVEL, row_span);
				}
				else
					talentTreeMap[talent.row() * 10 + talent.col()] = to_nga_table_row(dbc, talent.spell(), MAX_LEVEL);
>>>>>>> nga/zh_CN
			}
		}
	}
	int index = 0;
	for (auto i = talentTreeMap.begin(); i != talentTreeMap.end(); ++i)
	{
		s << i->second;
		index++;
	}

	s << "[/table]" << std::endl;

	return s.str();
}

<<<<<<< HEAD


static const std::array<nga_table_data_format, 19> __nga_conduit_data_format{ {
	{"", 0},
	{"导灵器", 0},
	{"图标", 0},
	{"描述", 30},
	{"1级", 0},
	{"2级", 0},
	{"3级", 0},
	{"4级", 0},
	{"5级", 0},
	{"6级", 0},
	{"7级", 0},
	{"8级", 0},
	{"9级", 0},
	{"10级", 0},
	{"11级", 0},
	{"12级", 0},
	{"13级", 0},
	{"14级", 0},
	{"15级", 0},
} };

enum nga_conduit_shaman_type
{
	e_elemental = 1,
	e_enhance = 2,
	e_restore = 3,
	e_force = 4,
};

struct nga_conduit_shaman_data
{
	unsigned conduit_spell_id;
	nga_conduit_shaman_type type;
};

static const std::array<nga_conduit_shaman_data, 16> __nga_master_conduit_id{ {
	{338329, e_restore},
	{338343, e_restore},
	{338346, e_restore},
	{338339, e_restore},
	{338325, e_enhance},
	{338322, e_enhance},
	{338318, e_enhance},
	{338331, e_enhance},
	{338131, e_elemental},
	{338303, e_elemental},
	{338307, e_elemental},
	{338252, e_elemental},
	{339182, e_force},
	{339183, e_force},
	{339185, e_force},
	{339186, e_force},
} };


static constexpr auto _nga_conduit_color_increase = util::make_static_map<unsigned, eNgaColor>({
	  { 0, nc_indigo },
	  { 1, nc_purple },
	  { 2, nc_darkblue },
	  { 3, nc_blue },
	  { 4, nc_royalblue },
	});

std::string _nga_to_conduit_table_row(const dbc_t& dbc, const spell_data_t* spell, int level, std::string rowspan = "")
{

	std::ostringstream s;
	s << "[tr]" << std::endl;

	s << rowspan;

	const spelltext_data_t& spell_text = dbc.spell_text(spell->id());
	const spelldesc_vars_data_t& spelldesc_vars = dbc.spell_desc_vars(spell->id());

	// Name
	std::string name_str = spell->name_cstr();
	s << nga_td(nga_align_center(name_str));

	// Icon image
	auto icon_url = nga_icon_url(spell->_icon_id);
	s << nga_td(nga_align_center(nga_img(icon_url)));

	// Desc
	if (spell_text.desc())
		s << nga_td(spell_text.desc());
	else
		s << nga_td("");

	// Rank
	const auto& conduit = conduit_entry_t::find_by_spellid(spell->id(), dbc.ptr);
	if (conduit.spell_id && conduit.spell_id == spell->id())
	{
		for (int i = 0; i < 15; ++i)
		{
			auto rank = conduit_rank_entry_t::find(conduit.id, i, dbc.ptr);
			double final_value = rank.value;
			if (abs(final_value) >= 1000)
			{
				final_value /= 1000.0;
			}

			eNgaColor rankColor= nc_blue;
			int colorIndex = i / 3;
			auto nc = _nga_conduit_color_increase.find(colorIndex);
			if (nc != _nga_conduit_color_increase.end())
			{
				rankColor = nc->second;
			}
			
			s << nga_td(nga_align_center(nga_font(nga_color(nga_number(final_value), rankColor))));
		}		
	}

	s << "[/tr]" << std::endl;

	return s.str();
}


void nga_to_conduit_talbe_row(const dbc_t& dbc, std::vector< const spell_data_t *> &spells, std::ostringstream &s, std::string rowspanName = "")
{
	std::string row_span = "[td rowspan=" + nga_number((double)spells.size()) + "]"+ rowspanName + "[/td]";
	bool bFirstLine = true;
	for (const spell_data_t *spell : spells)
	{
		if (bFirstLine)
		{
			s << _nga_to_conduit_table_row(dbc, spell, MAX_LEVEL, row_span);
			bFirstLine = false;
		}
		else
			s << _nga_to_conduit_table_row(dbc, spell, MAX_LEVEL);
	}
}



std::string nga_to_conduit_table(const dbc_t& dbc)
{
	std::ostringstream s;
	s << "[table]" << std::endl;

	// first row
	std::ostringstream sr;
	util::span<const nga_table_data_format> ngaData = ::util::make_span(__nga_conduit_data_format);
	for (auto data : ngaData)
	{
		sr << nga_td(nga_align_center(nga_b(data.value)), data.width);
	}
	s << nga_tr(sr.str());

	//int common_spell_number = 0;
	std::vector< const spell_data_t *> elemental_vector;
	std::vector< const spell_data_t *> enchance_vector;
	std::vector< const spell_data_t *> restore_vector;
	std::vector< const spell_data_t *> force_vector;
	std::vector< const spell_data_t *> common_vector;
	for (const spell_data_t &spell : spell_data_t::data())
	{
		if (spell.class_family() == 11)
		{
			const auto& conduit = conduit_entry_t::find_by_spellid(spell.id(), dbc.ptr);
			if (!(conduit.spell_id && conduit.spell_id == spell.id()))
			{
				continue;
			}

			bool bMasterConduit = false;
			for (auto conduitType : __nga_master_conduit_id)
			{
				if (conduitType.conduit_spell_id == spell.id())
				{
					bMasterConduit = true;
					switch (conduitType.type)
					{
					case e_elemental:
						elemental_vector.push_back(&spell);
						break;
					case e_enhance:
						enchance_vector.push_back(&spell);
						break;
					case e_restore:
						restore_vector.push_back(&spell);
						break;
					case e_force:
						force_vector.push_back(&spell);
						break;
					}
				}
			}

			if (bMasterConduit == false)
			{
				common_vector.push_back(&spell);
			}
		}
	}

	nga_to_conduit_talbe_row(dbc, elemental_vector, s, "元素");
	nga_to_conduit_talbe_row(dbc, enchance_vector, s, "增强");
	nga_to_conduit_talbe_row(dbc, restore_vector, s, "恢复");
	nga_to_conduit_talbe_row(dbc, force_vector, s, "盟约");
	nga_to_conduit_talbe_row(dbc, common_vector, s, "通用");


	s << "[/table]" << std::endl;

	return s.str();
}




std::string nga_to_lengendary_table(const dbc_t& dbc, unsigned shaman_type)
{
	std::ostringstream s;
	s << "[table]" << std::endl;

	// first row
	std::ostringstream sr;
	util::span<const nga_table_data_format> ngaData = ::util::make_span(__nga_conduit_data_format);
	for (auto data : ngaData)
	{
		sr << nga_td(nga_align_center(nga_b(data.value)), data.width);
	}
	s << nga_tr(sr.str());

	//int common_spell_number = 0;
	std::vector< const spell_data_t *> elemental_vector;
	std::vector< const spell_data_t *> enchance_vector;
	std::vector< const spell_data_t *> restore_vector;
	std::vector< const spell_data_t *> force_vector;
	std::vector< const spell_data_t *> common_vector;
	for (const spell_data_t &spell : spell_data_t::data())
	{
		if (spell.class_family() == 11)
		{
			const auto& conduit = conduit_entry_t::find_by_spellid(spell.id(), dbc.ptr);
			if (!(conduit.spell_id && conduit.spell_id == spell.id()))
			{
				continue;
			}

			bool bMasterConduit = false;
			for (auto conduitType : __nga_master_conduit_id)
			{
				if (conduitType.conduit_spell_id == spell.id())
				{
					bMasterConduit = true;
					switch (conduitType.type)
					{
					case e_elemental:
						elemental_vector.push_back(&spell);
						break;
					case e_enhance:
						enchance_vector.push_back(&spell);
						break;
					case e_restore:
						restore_vector.push_back(&spell);
						break;
					case e_force:
						force_vector.push_back(&spell);
						break;
					}
				}
			}

			if (bMasterConduit == false)
			{
				common_vector.push_back(&spell);
			}
		}
	}

	nga_to_conduit_talbe_row(dbc, elemental_vector, s, "元素");
	nga_to_conduit_talbe_row(dbc, enchance_vector, s, "增强");
	nga_to_conduit_talbe_row(dbc, restore_vector, s, "恢复");
	nga_to_conduit_talbe_row(dbc, force_vector, s, "盟约");
	nga_to_conduit_talbe_row(dbc, common_vector, s, "通用");


	s << "[/table]" << std::endl;

	return s.str();
}
=======
>>>>>>> nga/zh_CN
