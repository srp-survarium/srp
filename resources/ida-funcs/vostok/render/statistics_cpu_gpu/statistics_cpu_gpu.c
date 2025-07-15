void __userpurge vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
        vostok::render::statistics_cpu_gpu *this@<ecx>,
        int a2@<eax>,
        vostok::render::statistics_group *group,
        const char *name)
{
  vostok::render::statistics_base::statistics_base(
    (vostok::render::statistics_base *)a2,
    (vostok::render::statistics_group *)this,
    (char *)group);
  *(_DWORD *)a2 = &vostok::render::statistics_cpu_gpu::`vftable';
  vostok::render::statistics_float::statistics_float((vostok::render::statistics_float *)(a2 + 152), 0, 0, 6u);
  vostok::render::statistics_float::statistics_float((vostok::render::statistics_float *)(a2 + 496), 0, 0, 6u);
}
