vostok::render::material_effects_instance *__thiscall vostok::render::material_effects_instance::`scalar deleting destructor'(
        vostok::render::material_effects_instance *this,
        char a2)
{
  vostok::render::material_effects::~material_effects((vostok::render::material_effects *)this);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
