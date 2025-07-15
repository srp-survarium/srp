void __userpurge survarium::shared_statistics::reset_received_damage(
        unsigned __int8 player@<al>,
        survarium::shared_statistics *this)
{
  memset(&this->m_player_stats.elems[player].intermediate, 0, 0x50u);
}
