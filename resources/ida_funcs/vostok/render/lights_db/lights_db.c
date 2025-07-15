void __usercall vostok::render::lights_db::lights_db(vostok::render::lights_db *this@<ecx>, _DWORD *a2@<esi>)
{
  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  a2[4] = 0;
  a2[4] = vostok::collision::new_space_partitioning_tree(
            (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
            1.0,
            (unsigned int)&loc_19000);
}
