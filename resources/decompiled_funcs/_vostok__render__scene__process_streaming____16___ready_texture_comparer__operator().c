BOOL __usercall vostok::render::scene::process_streaming_::_16_::ready_texture_comparer::operator()@<eax>(
        const vostok::render::streaming_ready_texture *left@<ecx>,
        const vostok::render::streaming_ready_texture *right@<eax>,
        vostok::render::scene::process_streaming::__l16::ready_texture_comparer *this)
{
  return right->distance > left->distance;
}
