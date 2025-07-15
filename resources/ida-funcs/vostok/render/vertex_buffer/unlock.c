void __usercall vostok::render::vertex_buffer::unlock(vostok::render::vertex_buffer *this@<ecx>, int *a2@<eax>)
{
  vostok::render::untyped_buffer *v2; // ecx

  v2 = (vostok::render::untyped_buffer *)(a2[4] * a2[5]);
  a2[2] += (int)v2;
  vostok::render::untyped_buffer::unmap(v2, *a2);
}
