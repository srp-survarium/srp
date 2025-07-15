void __userpurge vostok::command_line::key::key(
        vostok::command_line::key *this@<ecx>,
        _DWORD *a2@<esi>,
        const char *full_name,
        const char *short_name,
        const char *category,
        const char *description,
        const char *argument_description)
{
  *a2 = a2 + 3;
  a2[1] = a2 + 3;
  a2[2] = a2 + 131;
  *((_BYTE *)a2 + 12) = 0;
  a2[132] = full_name;
  a2[133] = short_name;
  a2[134] = category;
  a2[135] = description;
  a2[131] = 0;
  a2[136] = argument_description;
  a2[137] = 0;
  vostok::debug::protected_call((void (__cdecl *)(void *))vostok::command_line::protected_key_construct, a2);
}
