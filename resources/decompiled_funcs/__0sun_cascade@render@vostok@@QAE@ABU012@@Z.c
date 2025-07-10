void __thiscall vostok::render::sun_cascade::sun_cascade(
        vostok::render::sun_cascade *this,
        vostok::render::sun_cascade *__that,
        const vostok::render::sun_cascade *__thata)
{
  const vostok::render::sun_cascade *v3; // ebx

  v3 = __thata;
  qmemcpy(__that, __thata, 0x40u);
  __that->rays.m_begin = (vostok::render::ray *)__that->rays.m_buffer;
  __that->rays.m_end = (vostok::render::ray *)__that->rays.m_buffer;
  __thata = (const vostok::render::sun_cascade *)v3->rays.m_end;
  vostok::buffer_vector<vostok::render::ray>::assign<vostok::render::ray const *>(
    &__that->rays,
    v3->rays.m_begin,
    (const vostok::render::ray *const *)&__thata);
  __that->size = v3->size;
  __that->bias = v3->bias;
  __that->reset_chain = v3->reset_chain;
}
