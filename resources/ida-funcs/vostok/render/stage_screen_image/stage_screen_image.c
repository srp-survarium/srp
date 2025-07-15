void __userpurge vostok::render::stage_screen_image::stage_screen_image(
        vostok::render::stage_screen_image *this@<edi>,
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::renderer *in_renderer)
{
  vostok::render::resource_manager *v3; // ecx
  vostok::render::res_declaration *v4; // eax
  vostok::render::effect_manager *v5; // ecx
  const D3D11_INPUT_ELEMENT_DESC *v6; // [esp-Ch] [ebp-50h]
  D3D11_INPUT_ELEMENT_DESC count; // [esp+8h] [ebp-3Ch] BYREF
  const char *v8; // [esp+24h] [ebp-20h]
  int v9; // [esp+28h] [ebp-1Ch]
  int v10; // [esp+2Ch] [ebp-18h]
  int v11; // [esp+30h] [ebp-14h]
  int v12; // [esp+34h] [ebp-10h]
  int v13; // [esp+38h] [ebp-Ch]
  int v14; // [esp+3Ch] [ebp-8h]

  vostok::render::stage::stage(this, context, in_renderer);
  this->__vftable = (vostok::render::stage_screen_image_vtbl *)&vostok::render::stage_screen_image::`vftable';
  this->m_present_effect.m_object = 0;
  this->m_decl_ptr.m_object = 0;
  this->m_textures.m_reference_count = 0;
  this->m_textures.m_container.m_begin = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)this->m_textures.m_container.m_buffer;
  this->m_textures.m_container.m_end = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)this->m_textures.m_container.m_buffer;
  this->m_textures.m_container.m_max_end = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this->m_textures.m_is_registered;
  count.Format = DXGI_FORMAT_R32G32_FLOAT;
  v10 = 16;
  v6 = (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  this->m_textures.m_is_registered = 0;
  count.SemanticName = "POSITIONT";
  count.SemanticIndex = 0;
  memset(&count.InputSlot, 0, 16);
  v8 = "TEXCOORD";
  v9 = 0;
  v11 = 0;
  v12 = 8;
  v13 = 0;
  v14 = 0;
  v4 = vostok::render::resource_manager::create_declaration(v3, v6, &count, 2u);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_decl_ptr,
    v4);
  vostok::render::effect_manager::create_effect<vostok::render::scr_quad_effect>(
    v5,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_present_effect);
  in_renderer = 0;
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
    (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)1,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this->m_textures.m_container,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_renderer);
}
