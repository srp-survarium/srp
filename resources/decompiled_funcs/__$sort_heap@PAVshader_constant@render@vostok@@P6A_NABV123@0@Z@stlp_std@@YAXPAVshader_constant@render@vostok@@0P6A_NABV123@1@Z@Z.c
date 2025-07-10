void __usercall stlp_std::sort_heap<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<edi>,
        vostok::render::shader_constant *__last@<eax>,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  vostok::render::shader_constant *v3; // esi
  vostok::render::shader_constant v4; // [esp-1Ch] [ebp-28h]

  if ( __last - __first > 1 )
  {
    v3 = __last - 1;
    do
    {
      v4.m_slot.m_value = v3->m_slot.m_value;
      v4.m_source.m_pointer = v3->m_source.m_pointer;
      v4.m_source.m_size = v3->m_source.m_size;
      v4.m_host = v3->m_host;
      stlp_std::__pop_heap<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),int>(
        v3,
        v3,
        __first,
        v4,
        __comp);
      --v3;
    }
    while ( ((int)v3 + 24 - (int)__first) / 24 > 1 );
  }
}
