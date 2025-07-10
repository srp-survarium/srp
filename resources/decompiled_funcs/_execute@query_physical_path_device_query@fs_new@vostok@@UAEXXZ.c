void __thiscall vostok::fs_new::query_physical_path_device_query::execute(
        vostok::fs_new::query_physical_path_device_query *this)
{
  vostok::fs_new::physical_path_info *physical_path_info; // [esp+4h] [ebp-158h]
  vostok::fs_new::physical_path_info result; // [esp+24h] [ebp-138h] BYREF

  physical_path_info = vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(
                         &this->m_device,
                         &result,
                         &this->m_path);
  this->m_result.device = physical_path_info->device;
  vostok::fs_new::physical_path_info_data::operator=(&this->m_result.data, &physical_path_info->data);
  this->m_result.parent = physical_path_info->parent;
}
