vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::animation::mixing::binary_tree_weight_node **a2@<esi>)
{
  vostok::animation::mixing::binary_tree_weight_node *m_object; // ecx
  vostok::animation::mixing::binary_tree_weight_node *v3; // eax
  int v4; // ecx

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    ++m_object->m_reference_count;
  }
  v4 = (int)*a2;
  *a2 = v3;
  if ( v4 )
  {
    if ( (*(_DWORD *)(v4 + 16))-- == 1 )
      (**(void (__thiscall ***)(int, _DWORD))v4)(v4, 0);
  }
  return (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)a2;
}


vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *__userpurge vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *object@<edi>,
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *this)
{
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *v2; // ebx
  vostok::resources::fs_task_unmount **v3; // eax
  vostok::resources::fs_task_unmount *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *)&this);
  return v2;
}


vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *__userpurge vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *object@<edi>,
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v2; // ebx
  vostok::animation::mixing::n_ary_tree_intrusive_base **v3; // eax
  vostok::animation::mixing::n_ary_tree_intrusive_base *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this);
  return v2;
}


vostok::render::render_target *__userpurge vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object@<edi>,
        vostok::render::render_target *this)
{
  vostok::render::render_target *v2; // ebx
  unsigned int *v3; // eax
  unsigned int v4; // ecx
  vostok::render::render_target *v5; // eax

  v2 = this;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_reference_count;
  v5 = this;
  v2->m_reference_count = v4;
  if ( v5 )
  {
    if ( !--v5->m_reference_count )
      vostok::render::resource_manager::release(this, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  return v2;
}


vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        vostok::render::render_target *object@<eax>)
{
  vostok::render::render_target *v2; // ecx
  vostok::render::render_target *m_object; // eax

  v2 = 0;
  if ( object )
  {
    ++object->m_reference_count;
    v2 = object;
  }
  m_object = this->m_object;
  this->m_object = v2;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        m_object,
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  return this;
}


vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        vostok::render::res_declaration *object@<eax>)
{
  vostok::render::res_declaration *v2; // ecx
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v4; // [esp+4h] [ebp-4h] BYREF

  v2 = 0;
  if ( object )
  {
    ++object->m_reference_count;
    v2 = object;
  }
  v4.m_object = this->m_object;
  this->m_object = v2;
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&v4);
  return this;
}


vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__userpurge vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        int *a2@<esi>,
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object)
{
  int *v3; // eax
  int v4; // ecx
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax

  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&object,
    object);
  v4 = *v3;
  *v3 = *a2;
  v5 = object;
  *a2 = v4;
  if ( v5 )
  {
    if ( !--v5->m_object )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)object);
  }
  return (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2;
}


vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        vostok::render::res_geometry *object@<eax>)
{
  vostok::render::res_geometry *v2; // ecx
  vostok::render::res_pass *m_object; // eax

  v2 = 0;
  if ( object )
  {
    ++object->m_reference_count;
    v2 = object;
  }
  m_object = (vostok::render::res_pass *)this->m_object;
  this->m_object = v2;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        m_object);
  }
  return this;
}


vostok::render::res_texture *__userpurge vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object@<edi>,
        vostok::render::res_texture *this)
{
  vostok::render::res_texture *v2; // ebx
  vostok::render::resource_manager **v3; // eax
  vostok::render::resource_manager *v4; // ecx
  vostok::render::res_texture *v5; // eax

  v2 = this;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    object);
  v4 = *v3;
  *v3 = (vostok::render::resource_manager *)v2->__vftable;
  v5 = this;
  v2->__vftable = (vostok::render::res_texture_vtbl *)v4;
  if ( v5 )
  {
    if ( v5->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        v4,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        this);
  }
  return v2;
}


vostok::render::res_texture *__userpurge vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::render::res_texture *object@<esi>,
        vostok::render::res_texture *this)
{
  vostok::render::res_texture *v2; // ebx
  vostok::render::resource_manager **v3; // eax
  vostok::render::resource_manager *v4; // ecx
  vostok::render::res_texture *v5; // eax

  v2 = this;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    object);
  v4 = *v3;
  *v3 = (vostok::render::resource_manager *)v2->__vftable;
  v5 = this;
  v2->__vftable = (vostok::render::res_texture_vtbl *)v4;
  if ( v5 )
  {
    if ( v5->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        v4,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        this);
  }
  return v2;
}


vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__userpurge vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object@<edi>,
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // ebx
  vostok::render::shader_buffer **v3; // eax
  vostok::render::shader_buffer *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this);
  return v2;
}


vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        vostok::render::shader_buffer *object@<edi>)
{
  vostok::render::shader_buffer *v2; // eax
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v4; // [esp+4h] [ebp-4h] BYREF

  v2 = 0;
  v4.m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&v4);
    ++object->m_reference_count;
    v2 = object;
  }
  v4.m_object = this->m_object;
  this->m_object = v2;
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&v4);
  return this;
}


vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *__userpurge vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *object@<edi>,
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this)
{
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v2; // ebx
  vostok::sound::sound_instance_proxy **v3; // eax
  vostok::sound::sound_instance_proxy *v4; // ecx
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v5; // eax
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v6; // eax

  v2 = this;
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v5 = this;
  v2->m_object = v4;
  if ( v5 )
  {
    v6 = v5 + 10;
    if ( v6->m_object-- == (vostok::sound::sound_instance_proxy *)1 )
      ((void (__thiscall *)(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *))this->m_object->m_finished_callback.functor.bound_memfunc_ptr.obj_ptr)(this);
  }
  return v2;
}


vostok::sound::sound_instance_proxy *__thiscall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this,
        vostok::sound::sound_instance_proxy *object)
{
  vostok::sound::sound_instance_proxy *v2; // ebx
  vostok::sound::sound_instance_proxy_vtbl **v3; // eax
  vostok::sound::sound_instance_proxy_vtbl *v4; // ecx
  vostok::sound::sound_instance_proxy *v5; // eax
  volatile int *p_m_reference_count; // eax

  v2 = object;
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)&object,
    0);
  v4 = *v3;
  *v3 = v2->__vftable;
  v5 = object;
  v2->__vftable = v4;
  if ( v5 )
  {
    p_m_reference_count = &v5->m_reference_count;
    if ( (*p_m_reference_count)-- == 1 )
      object->free_object(object);
  }
  return v2;
}


vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **__usercall vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>,
        vostok::render::hw_buffer_pool *a3@<esi>)
{
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  const vostok::render::untyped_buffer *v4; // esi

  v3 = 0;
  if ( this )
  {
    ++this->m_object;
    v3 = this;
  }
  v4 = (const vostok::render::untyped_buffer *)*a2;
  *a2 = v3;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v4, a3);
  }
  return a2;
}


vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *__userpurge vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *object@<edi>,
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v2; // ebx
  vostok::vfs::vfs_mount **v3; // eax
  vostok::vfs::vfs_mount *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&this);
  return v2;
}


vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *__userpurge vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this@<ecx>,
        int *a2@<esi>,
        vostok::vfs::vfs_mount *object)
{
  int *v3; // eax
  int v4; // ecx

  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&object,
    object);
  v4 = *v3;
  *v3 = *a2;
  *a2 = v4;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&object);
  return (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)a2;
}


vostok::render::res_xs<vostok::render::ps_data> *__userpurge vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object@<edi>,
        vostok::render::res_xs<vostok::render::ps_data> *this)
{
  vostok::render::res_xs<vostok::render::ps_data> *v2; // ebx
  unsigned int *v3; // eax
  unsigned int v4; // ecx
  vostok::render::res_xs<vostok::render::ps_data> *v5; // eax

  v2 = this;
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_reference_count;
  v5 = this;
  v2->m_reference_count = v4;
  if ( v5 )
  {
    if ( !--v5->m_reference_count )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this);
  }
  return v2;
}
