void __thiscall vostok::render::grass_world::populate(
        vostok::render::grass_world *this,
        vostok::render::scene *in_scene,
        vostok::render::scene *gw)
{
  vostok::buffer_vector<void const *> *v3; // ecx
  vostok::render::scene *v4; // ecx
  vostok::render::base_command *last_command; // eax
  bool i; // zf
  vostok::render::base_command *next; // eax
  signed int v8; // esi
  float v9; // xmm1_4
  vostok::render::grass_patch *v10; // eax
  vostok::render::grass_patch *v11; // ecx
  const vostok::render::grass_patch *v12; // eax
  vostok::buffer_vector<vostok::render::grass_patch> *v13; // ecx
  vostok::render::grass_patch *v14; // ecx
  vostok::render::grass_instance *v15; // ecx
  _DWORD *v16; // eax
  vostok::render::grass_patch *v17; // ecx
  vostok::math::float3 *v18; // esi
  vostok::math::float3 *v19; // ebx
  vostok::render::grass_patch *v20; // ecx
  bool v21; // [esp+4h] [ebp-40E8h]
  vostok::render::grass_instance *next_in_template; // [esp+10h] [ebp-40DCh]
  void *value; // [esp+14h] [ebp-40D8h] BYREF
  vostok::render::base_scene *m_object; // [esp+18h] [ebp-40D4h]
  float v25; // [esp+1Ch] [ebp-40D0h]
  int v26; // [esp+20h] [ebp-40CCh]
  float v27; // [esp+24h] [ebp-40C8h]
  vostok::collision::space_partitioning_tree in_size[3]; // [esp+28h] [ebp-40C4h] BYREF
  vostok::collision::space_partitioning_tree in_collision_tree; // [esp+34h] [ebp-40B8h] BYREF

  vostok::render::grass_world::remove_patches(this, in_scene);
  value = in_scene;
  vostok::buffer_vector<void const *>::push_back(v3, (int)&loc_1C6188 + (_DWORD)gw, (const void **)&value);
  vostok::render::scene::process_pending_remove_texture_instances(v4, (int)gw);
  last_command = in_scene->last_command;
  m_object = in_scene->next_scene.m_object;
  for ( i = last_command == (vostok::render::base_command *)m_object; ; i = (char *)value + 36 == (char *)m_object )
  {
    value = last_command;
    if ( i )
      break;
    next = last_command->next;
    next_in_template = (vostok::render::grass_instance *)next;
    if ( next )
    {
      in_size[1].__vftable = 0;
      while ( 1 )
      {
        v25 = *(float *)&next->m_cache_line_pad_$31[42];
        v26 = *(_DWORD *)&next->m_cache_line_pad_$31[46];
        v27 = *(float *)&next->m_cache_line_pad_$31[50];
        v8 = vostok::math::floor(v25 * 0.0625);
        v9 = (float)(int)vostok::math::floor(v27 * 0.0625);
        v10 = *(vostok::render::grass_patch **)in_scene->m_streaming_texture_instance_allocator.m_buffer;
        v11 = *(vostok::render::grass_patch **)&in_scene->m_streaming_texture_instance_allocator.m_buffer[4];
        *(float *)&in_size[0].__vftable = (float)((float)v8 * 16.0) + gran1;
        *(float *)&in_size[2].__vftable = (float)(v9 * 16.0) + gran1;
        if ( v10 == v11 )
        {
LABEL_12:
          v10 = 0;
        }
        else
        {
          while ( v25 < v10->m_aabb.min.x
               || v27 < v10->m_aabb.min.z
               || v10->m_aabb.max.x < v25
               || v10->m_aabb.max.z < v27
               || value != v10->m_template )
          {
            if ( ++v10 == v11 )
              goto LABEL_12;
          }
        }
        if ( v10 )
        {
          next_in_template->next_in_patch = 0;
          ++v10->m_instances.m_size;
          if ( v10->m_instances.m_first )
            v10->m_instances.m_last->next_in_patch = next_in_template;
          else
            v10->m_instances.m_first = next_in_template;
          v10->m_instances.m_last = next_in_template;
          v15 = next_in_template;
        }
        else
        {
          vostok::render::grass_patch::grass_patch(
            v11,
            &in_collision_tree,
            *(vostok::collision::space_partitioning_tree_vtbl **)&in_scene->m_streaming_texture_instance_allocator.m_buffer[120],
            (vostok::collision::space_partitioning_tree_vtbl *)value,
            in_size);
          vostok::buffer_vector<vostok::render::grass_patch>::push_back(
            v13,
            (int)in_scene->m_streaming_texture_instance_allocator.m_buffer,
            v12);
          vostok::render::grass_patch::~grass_patch(
            v14,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_collision_tree);
          v15 = next_in_template;
          v16 = (_DWORD *)(*(_DWORD *)&in_scene->m_streaming_texture_instance_allocator.m_buffer[4] - 16556);
          next_in_template->next_in_patch = 0;
          ++*v16;
          if ( v16[2] )
            *(_DWORD *)(v16[3] + 8) = next_in_template;
          else
            v16[2] = next_in_template;
          v16[3] = next_in_template;
        }
        next_in_template = v15->next_in_template;
        if ( !next_in_template )
          break;
        next = (vostok::render::base_command *)v15->next_in_template;
      }
    }
    last_command = (vostok::render::base_command *)((char *)value + 36);
  }
  vostok::render::scene::gather_streamable_textures(in_scene, gw);
  v18 = *(vostok::math::float3 **)in_scene->m_streaming_texture_instance_allocator.m_buffer;
  v19 = *(vostok::math::float3 **)&in_scene->m_streaming_texture_instance_allocator.m_buffer[4];
  while ( v18 != v19 )
  {
    vostok::render::grass_patch::init_collision(v17, (int)v18);
    vostok::render::grass_patch::create_render_buffer(v20, v18, v21);
    v18 = (vostok::math::float3 *)((char *)v18 + 16568);
  }
}
