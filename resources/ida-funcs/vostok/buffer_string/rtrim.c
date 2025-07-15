void __thiscall vostok::buffer_string::rtrim(vostok::buffer_string *this, vostok::buffer_string *string)
{
  unsigned int v2; // ebp
  unsigned int v3; // esi

  v2 = strlen(".material");
  if ( v2 )
  {
    while ( 1 )
    {
      v3 = string->m_end - string->m_begin;
      if ( !(v3
           ? vostok::strings::ends_with(string->m_begin, v3, ".material", strlen(".material"))
           : &string_to_search_for[strlen(".material") + 1] == "material") )
        break;
      string->m_end -= v2;
      *string->m_end = 0;
    }
  }
}


void __thiscall vostok::buffer_string::rtrim(vostok::buffer_string *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  *--this->m_end = 0;
}
