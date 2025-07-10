void __usercall stlp_std::priv::__ufill<vostok::render::ui::vertex *,vostok::render::ui::vertex,int>(
        vostok::render::ui::vertex *__first@<edi>,
        vostok::render::ui::vertex *__last@<eax>,
        const vostok::render::ui::vertex *__x@<esi>)
{
  int v3; // eax
  unsigned int *p_m_color; // ecx

  v3 = __last - __first;
  if ( v3 > 0 )
  {
    p_m_color = &__first->m_color;
    do
    {
      if ( p_m_color != (unsigned int *)16 )
        *(vostok::render::ui::vertex *)(p_m_color - 4) = *__x;
      --v3;
      p_m_color += 7;
    }
    while ( v3 > 0 );
  }
}
