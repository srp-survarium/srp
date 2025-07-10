void __thiscall survarium::game_world_ui::set_base_capture_progress(
        survarium::game_world_ui *this,
        stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *progress,
        stlp_std::priv::_Rb_tree_node_base *point_id,
        unsigned int point_ida)
{
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *v4; // esi
  stlp_std::priv::_Rb_tree_node_base *M_node; // eax
  stlp_std::priv::_Rb_tree_node_base *v6; // esi
  char *v7; // edi
  stlp_std::priv::_Rb_tree_node_base *v8; // edx
  survarium::flash_value args[3]; // [esp+18h] [ebp-88h] BYREF
  char buff[64]; // [esp+60h] [ebp-40h] BYREF
  unsigned int progressa; // [esp+A8h] [ebp+8h]

  v4 = stlp_std::map<unsigned int,survarium::base_point_stats,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats>>>::operator[]<unsigned int>(
         (stlp_std::map<unsigned int,survarium::base_point_stats,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats> > > *)&point_ida,
         progress + 3);
  if ( point_id == v4->_M_node )
    vostok::sprintf<64>((char (*)[64])buff, "captured!", point_ida);
  else
    vostok::sprintf<64>((char (*)[64])buff, "(%d/%d)", point_id, v4->_M_node);
  M_node = progress[10]._M_node;
  progressa = (__int64)((double)(unsigned int)point_id / (double)(unsigned int)v4->_M_node * 100.0);
  if ( M_node )
  {
    if ( M_node != (stlp_std::priv::_Rb_tree_node_base *)1 )
      return;
    `vector constructor iterator'(
      args[0].body,
      0x18u,
      3,
      (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
    if ( (args[0].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[0].body + 8))(
        *(_DWORD *)args[0].body,
        args,
        *(_DWORD *)&args[0].body[8]);
      *(_DWORD *)args[0].body = 0;
    }
    *(_DWORD *)&args[0].body[8] = 3;
    v7 = (char *)&buf;
  }
  else
  {
    `vector constructor iterator'(
      args[0].body,
      0x18u,
      3,
      (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
    v6 = v4[2]._M_node;
    if ( (args[0].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[0].body + 8))(
        *(_DWORD *)args[0].body,
        args,
        *(_DWORD *)&args[0].body[8]);
      *(_DWORD *)args[0].body = 0;
    }
    *(_DWORD *)&args[0].body[8] = v6;
    v7 = buff;
  }
  *(_DWORD *)&args[0].body[4] = 4;
  survarium::flash_value::SetString(&args[1], v7);
  if ( (args[2].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[2].body + 8))(
      *(_DWORD *)args[2].body,
      &args[2],
      *(_DWORD *)&args[2].body[8]);
    *(_DWORD *)args[2].body = 0;
  }
  v8 = progress[1]._M_node;
  *(_DWORD *)&args[2].body[4] = 4;
  *(_DWORD *)&args[2].body[8] = progressa;
  Scaleform::GFx::Movie::Invoke(
    (Scaleform::GFx::Movie *)v8[16]._M_left->_M_parent,
    "root.set_capture_progress",
    0,
    (const Scaleform::GFx::Value *)args,
    3u);
  `vector destructor iterator'(
    args[0].body,
    0x18u,
    3,
    (void (__thiscall *)(void *))survarium::flash_value::~flash_value);
}
