void __thiscall vostok::render::sun_cascade::sun_cascade(
        vostok::render::sun_cascade *this,
        vostok::render::sun_cascade *__that,
        vostok::render::ray *end)
{
  vostok::render::ray *v3; // ebx

  v3 = end;
  qmemcpy(__that, end, 0x40u);
  __that->rays.m_begin = (vostok::render::ray *)__that->rays.m_buffer;
  __that->rays.m_end = (vostok::render::ray *)__that->rays.m_buffer;
  __that->rays.m_max_end = (vostok::render::ray *)&__that->size;
  end = (vostok::render::ray *)LODWORD(v3[2].origin.z);
  vostok::buffer_vector<vostok::render::ray>::assign<vostok::render::ray const *>(
    &__that->rays,
    (const vostok::render::ray *)LODWORD(v3[2].origin.y),
    (const vostok::render::ray **)&end);
  __that->size = v3[11].direction.y;
  __that->bias = v3[11].direction.z;
  __that->reset_chain = LOBYTE(v3[11].origin.x);
}
