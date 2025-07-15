void __usercall vostok::render::defer_execution(
        vostok::render::base_command *command@<eax>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene@<esi>)
{
  vostok::render::base_command *last_command; // edx

  command->deferred_next = 0;
  last_command = scene->m_object->last_command;
  if ( last_command )
    last_command->deferred_next = command;
  else
    scene->m_object->first_command = command;
  scene->m_object->last_command = command;
}


void __usercall vostok::render::defer_execution(
        vostok::render::base_command *command@<eax>,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view@<esi>)
{
  vostok::render::base_command *last_command; // edx

  command->deferred_next = 0;
  last_command = scene_view->m_object->last_command;
  if ( last_command )
    last_command->deferred_next = command;
  else
    scene_view->m_object->first_command = command;
  scene_view->m_object->last_command = command;
}
