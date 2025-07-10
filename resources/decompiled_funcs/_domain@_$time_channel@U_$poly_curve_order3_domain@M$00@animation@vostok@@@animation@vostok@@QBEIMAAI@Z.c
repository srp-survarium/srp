int __userpurge vostok::animation::time_channel<vostok::animation::poly_curve_order3_domain<float,1>>::domain@<eax>(
        vostok::animation::time_channel<vostok::animation::poly_curve_order3_domain<float,1> > *this@<esi>,
        int a2@<ecx>,
        float a3@<xmm2>,
        unsigned int *current_domain)
{
  unsigned int m_knots_count; // ecx
  unsigned int m_internal_memory_position; // eax
  float v7; // xmm0_4
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ebx
  unsigned int v11; // edi
  int i; // ebp
  int result; // eax
  bool do_debug_break; // [esp+1h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(a2);
  m_knots_count = this->m_knots_count;
  m_internal_memory_position = this->m_internal_memory_position;
  v7 = *(float *)((char *)this + 20 * this->m_knots_count + m_internal_memory_position - 4);
  if ( *(float *)((char *)&this[2 * this->m_knots_count].m_knots_count + m_internal_memory_position) < a3 )
  {
    if ( v7 >= a3 )
      v7 = a3;
  }
  else
  {
    v7 = *(float *)((char *)&this[2 * this->m_knots_count].m_knots_count + m_internal_memory_position);
  }
  if ( !HIBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2])
    && v7 < *(float *)((char *)&this[2 * m_knots_count].m_knots_count + this->m_internal_memory_position) )
  {
    v8 = `vostok::animation::time_channel<vostok::animation::poly_curve_order3_domain<float,1>>::domain'::`12'::occurances_left;
    if ( `vostok::animation::time_channel<vostok::animation::poly_curve_order3_domain<float,1>>::domain'::`12'::occurances_left == -1 )
      v8 = 10;
    `vostok::animation::time_channel<vostok::animation::poly_curve_order3_domain<float,1>>::domain'::`12'::occurances_left = v8 - 1;
    if ( v8 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2]
      + 3,
        assert_untyped,
        "assertion_failed",
        "t >= knots()[0]",
        "C:\\survarium\\sources\\vostok/animation/time_channel_inline.h",
        "vostok::animation::time_channel<struct vostok::animation::poly_curve_order3_domain<float,1> >::domain",
        0x54u);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    m_knots_count = this->m_knots_count;
    v7 = *(float *)((char *)&this[2 * this->m_knots_count].m_knots_count + this->m_internal_memory_position);
  }
  if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3])
    && *(float *)((char *)this + 20 * m_knots_count + this->m_internal_memory_position - 4) < v7 )
  {
    v9 = `vostok::animation::time_channel<vostok::animation::poly_curve_order3_domain<float,1>>::domain'::`29'::occurances_left;
    if ( `vostok::animation::time_channel<vostok::animation::poly_curve_order3_domain<float,1>>::domain'::`29'::occurances_left == -1 )
      v9 = 10;
    `vostok::animation::time_channel<vostok::animation::poly_curve_order3_domain<float,1>>::domain'::`29'::occurances_left = v9 - 1;
    if ( v9 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3],
        assert_untyped,
        "assertion_failed",
        "t <= knots()[m_knots_count-1]",
        "C:\\survarium\\sources\\vostok/animation/time_channel_inline.h",
        "vostok::animation::time_channel<struct vostok::animation::poly_curve_order3_domain<float,1> >::domain",
        0x55u);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    m_knots_count = this->m_knots_count;
    v7 = *(float *)((char *)this + 20 * this->m_knots_count + this->m_internal_memory_position - 4);
  }
  v10 = this->m_internal_memory_position;
  v11 = *current_domain;
  for ( i = 0; ; ++i )
  {
    result = v11 % m_knots_count;
    if ( v7 >= *(float *)((char *)&this[2 * m_knots_count].m_knots_count + 4 * (v11 % m_knots_count) + v10)
      && *(float *)((char *)&this[2 * m_knots_count].m_internal_memory_position + 4 * result + v10) >= v7 )
    {
      break;
    }
    ++v11;
  }
  *current_domain = result;
  return result;
}
