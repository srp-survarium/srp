void __thiscall vostok::fs_new::custom_operation_query::execute(vostok::fs_new::custom_operation_query *this)
{
  vostok::fs_new::device_file_system_interface *m_device_file_system; // [esp+134h] [ebp-10h]
  vostok::fs_new::synchronous_device_interface device; // [esp+138h] [ebp-Ch] BYREF

  m_device_file_system = this->m_device.m_device_file_system;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_device_file_system);
  device.m_synchronize_query = 0;
  device.m_device.m_device_file_system = m_device_file_system;
  device.m_out_of_memory = 0;
  this->m_result = boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
                     (boost::function1<unsigned int,char const *> *)&this->m_args,
                     (const char *)&device);
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&device);
}
