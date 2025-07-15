void __usercall vostok::render::renderer::execute_stages(vostok::render::renderer *this@<ecx>, int a2@<edi>)
{
  vostok::render::event_query *v2; // ecx
  vostok::render::event_query *v3; // ecx
  vostok::timing::timer *v4; // ecx
  vostok::render::event_query *v5; // ecx
  vostok::render::event_query *v6; // ecx
  vostok::timing::timer *v7; // ecx
  vostok::render::event_query *v8; // ecx
  vostok::render::event_query *v9; // ecx
  _DWORD *v10; // esi
  unsigned int *dips; // ebx
  unsigned int v12; // edx
  vostok::timing::timer *v13; // ecx
  vostok::timing::timer *v14; // ecx
  vostok::render::event_query *v15; // ecx
  vostok::render::event_query *v16; // ecx
  vostok::timing::timer *v17; // ecx
  float v18; // xmm0_4
  _DWORD *i; // esi
  int v20; // [esp+Ch] [ebp-Ch]
  unsigned int v21; // [esp+10h] [ebp-8h]
  float v22; // [esp+10h] [ebp-8h]
  _DWORD *v23; // [esp+14h] [ebp-4h]

  if ( s_execute_stages )
  {
    *(_DWORD *)(a2 + 188) = 0;
    if ( (unsigned __int8)vostok::render::renderer::do_stages_profiling((vostok::render::renderer *)a2) )
    {
      vostok::render::event_query::issue(v2, *(ID3D11Asynchronous ***)(a2 + 216));
      vostok::render::event_query::wait(v3, *(ID3D11Query ***)(a2 + 216));
      vostok::timing::timer::start(v4, (LARGE_INTEGER *)(a2 + 192));
      vostok::render::event_query::issue(v5, *(ID3D11Asynchronous ***)(a2 + 216));
      vostok::render::event_query::wait(v6, *(ID3D11Query ***)(a2 + 216));
      *(float *)(a2 + 188) = vostok::timing::timer::get_elapsed_sec(v7, a2 + 192) * 1000.0;
    }
    if ( (unsigned __int8)vostok::render::renderer::do_stages_profiling((vostok::render::renderer *)a2) )
    {
      vostok::render::event_query::issue(v8, *(ID3D11Asynchronous ***)(a2 + 216));
      vostok::render::event_query::wait(v9, *(ID3D11Query ***)(a2 + 216));
    }
    v10 = *(_DWORD **)(a2 + 344);
    v23 = v10;
    if ( v10 != *(_DWORD **)(a2 + 348) )
    {
      dips = s_render_stages[0].dips;
      do
      {
        v21 = *v10;
        dips[1] = *v10;
        if ( v21 )
        {
          v20 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7428);
          if ( (unsigned __int8)vostok::render::renderer::do_stages_profiling((vostok::render::renderer *)a2) )
          {
            vostok::timing::timer::start(v13, (LARGE_INTEGER *)(a2 + 192));
            v12 = v21;
            v10 = v23;
          }
          (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v12 + 4))(v12);
          if ( (unsigned __int8)vostok::render::renderer::do_stages_profiling((vostok::render::renderer *)a2) )
          {
            *dips = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                              + 7428)
                  - v20;
            *((double *)dips - 1) = vostok::timing::timer::get_elapsed_sec(v14, a2 + 192) * 1000.0;
            vostok::render::event_query::issue(v15, *(ID3D11Asynchronous ***)(a2 + 216));
            vostok::render::event_query::wait(v16, *(ID3D11Query ***)(a2 + 216));
            v22 = vostok::timing::timer::get_elapsed_sec(v17, a2 + 192) * 1000.0 - *(float *)(a2 + 188);
            if ( v22 <= 0.0 )
              v18 = 0.0;
            else
              v18 = v22;
            v10 = v23;
            *((double *)dips - 2) = v18;
          }
        }
        ++v10;
        dips += 6;
        v23 = v10;
      }
      while ( v10 != *(_DWORD **)(a2 + 348) );
    }
    for ( i = *(_DWORD **)(a2 + 344); i != *(_DWORD **)(a2 + 348); ++i )
    {
      if ( *i )
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*i + 8))(*i);
    }
  }
}
