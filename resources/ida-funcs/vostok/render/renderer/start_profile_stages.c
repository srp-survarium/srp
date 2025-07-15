void __usercall vostok::render::renderer::start_profile_stages(vostok::render::renderer *this@<ecx>, int a2@<edi>)
{
  vostok::render::event_query *v2; // ecx
  vostok::render::event_query *v3; // ecx
  vostok::timing::timer *v4; // ecx
  vostok::timing::timer *v5; // ecx
  vostok::render::event_query *v6; // ecx
  vostok::render::event_query *v7; // ecx
  vostok::timing::timer *v8; // ecx
  float v9; // xmm0_4
  float v10; // [esp+Ch] [ebp-4h]

  if ( (unsigned __int8)vostok::render::renderer::do_stages_profiling((vostok::render::renderer *)a2) )
  {
    vostok::render::event_query::issue(v2, *(ID3D11Asynchronous ***)(a2 + 216));
    vostok::render::event_query::wait(v3, *(ID3D11Query ***)(a2 + 216));
    vostok::timing::timer::start(v4, (LARGE_INTEGER *)(a2 + 192));
  }
  if ( (unsigned __int8)vostok::render::renderer::do_stages_profiling((vostok::render::renderer *)a2) )
  {
    s_visibility_stage_stats.dips[0] = 0;
    s_visibility_stage_stats.elapsed_cpu_msec[0] = vostok::timing::timer::get_elapsed_sec(v5, a2 + 192) * 1000.0;
    s_visibility_stage_stats.stg = *(vostok::render::stage **)(a2 + 500);
    vostok::render::event_query::issue(v6, *(ID3D11Asynchronous ***)(a2 + 216));
    vostok::render::event_query::wait(v7, *(ID3D11Query ***)(a2 + 216));
    v10 = vostok::timing::timer::get_elapsed_sec(v8, a2 + 192) * 1000.0 - *(float *)(a2 + 188);
    if ( v10 <= 0.0 )
      v9 = 0.0;
    else
      v9 = v10;
    s_visibility_stage_stats.elapsed_gpu_msec[0] = v9;
  }
}
