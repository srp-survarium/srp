void __cdecl vostok::buffer_vector<vostok::ai::planning::object_instance>::construct(
        vostok::ai::planning::object_instance *p,
        const vostok::ai::planning::object_instance *value)
{
  char *v2; // [esp+20h] [ebp-4h]

  v2 = (char *)operator new(0x114u, p);
  if ( v2 )
  {
    *(_DWORD *)v2 = value->m_type;
    *((_DWORD *)v2 + 1) = value->m_instance;
    vostok::fixed_string<256>::fixed_string<256>((vostok::fixed_string<256> *)(v2 + 8), &value->m_caption);
  }
}
