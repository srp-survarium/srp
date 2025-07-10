void __userpurge survarium::game::load(
        survarium::game *this@<ecx>,
        int a2@<edi>,
        vostok::resources::request *project_resource_name,
        const vostok::variant<32> **requests_begin,
        const vostok::variant<32> **requests_end,
        const vostok::variant<32> **user_datas_begin,
        const boost::function<void __cdecl(vostok::resources::queries_result &)> *callback)
{
  survarium::game *v7; // eax

  v7 = *(survarium::game **)(a2 + 1552);
  if ( v7 != this )
  {
    *(_DWORD *)(a2 + 1556) = v7;
    LOBYTE(v7->vostok::engine_user::world::__vftable) = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(a2 + 1552), (const char *)this);
  }
  survarium::game_world::load(
    *(survarium::game_world **)(a2 + 1552),
    (survarium::game_world *)(a2 + 152),
    *(vostok::resources::request **)(a2 + 1552),
    project_resource_name,
    requests_begin,
    requests_end,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)user_datas_begin);
  *(_BYTE *)(a2 + 1025) = 0;
}
