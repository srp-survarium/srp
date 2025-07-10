void __userpurge vostok::render::scene_renderer::scene_renderer(
        vostok::render::one_way_render_channel *channel@<ecx>,
        vostok::render::engine::world *render_engine_world@<eax>,
        vostok::render::scene_renderer *this,
        vostok::math::frustum *allocator,
        vostok::math::frustum *frustum_listener)
{
  vostok::memory::base_allocator *v5; // edx
  const vostok::math::float4x4 *v6; // eax
  const void *v7; // eax
  float v8; // [esp+Ch] [ebp-CCh]
  float v9; // [esp+10h] [ebp-C8h]
  float v10; // [esp+14h] [ebp-C4h]
  vostok::math::float4x4 v11; // [esp+1Ch] [ebp-BCh] BYREF
  vostok::math::frustum v12; // [esp+5Ch] [ebp-7Ch] BYREF

  v5 = vostok::render::logic::g_allocator;
  this->m_render_engine_world = render_engine_world;
  this->m_channel = channel;
  this->m_allocator = v5;
  this->m_frustum_listener = allocator;
  qmemcpy((void *)&this->m_view, vostok::math::float4x4::identity(&v11), sizeof(this->m_view));
  vostok::math::create_perspective_projection(
    COERCE_VOSTOK_MATH_(1.3333334),
    COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(0.1),
    1000.0,
    v8,
    v9,
    v10);
  if ( this->m_frustum_listener )
  {
    v6 = vostok::math::mul4x4(&this->m_view, &this->m_projection);
    vostok::math::frustum::frustum(&v12, v6);
    qmemcpy(this->m_frustum_listener, v7, sizeof(vostok::math::frustum));
  }
}
