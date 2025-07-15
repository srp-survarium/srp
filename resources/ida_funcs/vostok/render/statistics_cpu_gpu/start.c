void __thiscall vostok::render::statistics_cpu_gpu::start(vostok::render::statistics_cpu_gpu *this)
{
  this->cpu_time.start(&this->cpu_time);
  this->gpu_time.start(&this->gpu_time);
}
