// ==========================================================================
// Dedmonwakeen's Raid DPS/TPS Simulator.
// Send questions to natehieter@gmail.com
// ==========================================================================

#ifndef SC_REPORT_HPP
#define SC_REPORT_HPP

#include <array>
#include <fstream>
#include <iosfwd>
#include <sstream>

#include "config.hpp"
#include "sc_enums.hpp"
#include "sc_highchart.hpp"
#include "util/io.hpp"
#include "util/util.hpp"
#include "util/chrono.hpp"

// see if we can get rid of these includes by adjusting spell_decorator_t
#include "action/sc_action.hpp"
#include "buff/sc_buff.hpp"
#include "item/item.hpp"
#include "report/reports.hpp"
#include "sim/sc_sim.hpp"
#include "dbc/dbc.hpp"

struct player_t;
struct action_t;
struct buff_t;
struct item_t;
struct xml_node_t;
struct sc_timeline_t;
struct spell_data_t;
class extended_sample_data_t;
struct player_processed_report_information_t;
struct sim_report_information_t;
struct spell_data_expr_t;
struct artifact_power_t;

/**
 * Automatic Timer reporting the time between construction and desctruction of
 * the object.
 */
struct Timer
{
private:
  std::string title;
  std::ostream& out;
  chrono::wall_clock::time_point start_time;
  bool started;

public:
  Timer( std::string title, std::ostream& out )
    : title( std::move( title ) ),
      out( out ),
      started( false )
  { }

  void start()
  {
    start_time = chrono::wall_clock::now();
    started = true;
  }

  ~Timer()
  {
    if ( started )
    {
      fmt::print( out, "{} took {}seconds.", title, chrono::elapsed_fp_seconds( start_time ) );
      out << std::endl;
    }
  }
};

#include "charts.hpp"


// Report helpers
namespace report_helper
{
  void print_html_sample_data(report::sc_html_stream&, const player_t&, const extended_sample_data_t&, const std::string& name, int columns = 1);

bool output_scale_factors(const player_t* p);

void generate_player_charts(player_t&, player_processed_report_information_t&);
void generate_player_buff_lists(player_t&, player_processed_report_information_t&);
std::vector<std::string> beta_warnings();
std::string pretty_spell_text( const spell_data_t& default_spell, const std::string& text, const player_t& p );
inline std::string pretty_spell_text( const spell_data_t& default_spell, const char* text, const player_t& p )
{
  return text ? pretty_spell_text( default_spell, std::string( text ), p ) : std::string();
}

bool check_gear(player_t& p, sim_t& sim);
}  // namespace report
#endif  // SC_REPORT_HPP
