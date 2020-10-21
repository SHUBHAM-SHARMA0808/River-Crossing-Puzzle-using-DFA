typedef struct state
{
	char left_bank[4];
	char right_bank[4];
	/*struct state *move_m_to_right;
	struct state *move_mg_to_right;
	struct state *move_mw_to_right;
	struct state *move_mc_to_right;
	struct state *move_m_to_left;
	struct state *move_mg_to_left;
	struct state *move_mw_to_left;
	struct state *move_mc_to_left;*/
	struct state *move[8];
}STATE;