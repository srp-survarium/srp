void __userpurge vostok::render::scene_renderer::scene_renderer(
        vostok::render::engine::world *render_engine_world@<eax>,
        vostok::math::float4x4 *a2@<ecx>,
        vostok::render::scene_renderer *this,
        vostok::render::one_way_render_channel *channel,
        vostok::memory::base_allocator *allocator,
        vostok::math::frustum *frustum_listener)
{
  long double v6; // rdi
  vostok::math::float4x4 *v7; // eax
  const void *v8; // eax
  vostok::math::frustum v9; // [esp+1Ch] [ebp-B8h] BYREF
  vostok::math::float4x4 v10; // [esp+94h] [ebp-40h] BYREF

  this->m_render_engine_world = render_engine_world;
  this->m_channel = channel;
  this->m_allocator = allocator;
  this->m_frustum_listener = frustum_listener;
  qmemcpy(&this->m_view, vostok::math::float4x4::identity(a2, &v10), sizeof(this->m_view));
  LODWORD(v6) = &this->m_projection;
  HIDWORD(v6) = &this->m_projection;
  vostok::math::create_perspective_projection(
    v6,
    1.5707964,
    (vostok::math *)LODWORD(v6),
    COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(1.3333334),
    0.1,
    1000.0);
  if ( this->m_frustum_listener )
  {
    v7 = vostok::math::mul4x4(&this->m_projection, &this->m_view, &v10);
    vostok::math::frustum::frustum(&v9, v7);
    qmemcpy(this->m_frustum_listener, v8, sizeof(vostok::math::frustum));
  }
}
