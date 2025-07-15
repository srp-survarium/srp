vostok::render::material_effects_instance *__userpurge vostok::render::material_effects_instance::`scalar deleting destructor'@<eax>(
        vostok::render::material_effects_instance *this@<ecx>,
        unsigned int ebx0@<ebx>,
        const char *a3@<edi>,
        char a2)
{
  vostok::render::material_effects_instance::~material_effects_instance(this, ebx0, a3, (const char *)this, this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
