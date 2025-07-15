void __usercall vostok::render::scene::remove_light(vostok::render::scene *this@<ecx>, unsigned int id@<eax>)
{
  int v2; // esi
  vostok::render::light_data *v3; // edi
  vostok::render::light *v4; // ecx
  vostok::buffer_vector<vostok::render::light_data> *v5; // ecx
  vostok::render::light *v6; // [esp-4h] [ebp-14h]
  int m_object; // [esp-4h] [ebp-14h]
  vostok::render::light_data *end; // [esp+8h] [ebp-8h] BYREF
  unsigned int __val; // [esp+Ch] [ebp-4h] BYREF

  v2 = *(int *)((char *)&dword_8B9660 + (_DWORD)this);
  __val = id;
  if ( id != *(_DWORD *)(v2 + 8208) )
  {
    v3 = stlp_std::find<vostok::render::light_data *,unsigned int>(
           *(vostok::render::light_data **)v2,
           &__val,
           *(vostok::render::light_data **)(v2 + 4));
    v4 = v6;
    m_object = (int)v3->light.m_object;
    end = v3;
    vostok::render::light::remove_collision(v4, m_object);
    __val = (unsigned int)&v3[1];
    vostok::buffer_vector<vostok::render::light_data>::erase(
      v5,
      (vostok::render::light_data *const *)v2,
      &end,
      (vostok::render::light_data **)&__val);
  }
}
