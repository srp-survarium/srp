void __usercall vostok::resources::game_resources_manager::release_resource(
        vostok::resources::game_resources_manager *this@<eax>,
        vostok::resources::resource_base *resource@<edi>)
{
  vostok::resources::releasing_functionality releasing; // [esp+0h] [ebp-4h] BYREF

  releasing.m_data = &this->m_data;
  vostok::resources::releasing_functionality::release_resource(&releasing, resource);
}
