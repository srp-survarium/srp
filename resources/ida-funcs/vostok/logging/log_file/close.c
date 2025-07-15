volatile __int32 *__thiscall vostok::logging::log_file::close(vostok::logging::log_file *this)
{
  vostok::logging::log_file *v1; // edi
  volatile __int32 *result; // eax
  volatile __int32 v3; // esi
  __int32 v4; // [esp+4h] [ebp-4h] BYREF

  v1 = vostok::core::g_log_file;
  result = (volatile __int32 *)&vostok::core::g_log_file->m_file;
  if ( vostok::core::g_log_file->m_file )
  {
    v3 = *result;
    _InterlockedExchange(result, 0);
    _InterlockedExchange(&v4, (__int32)result);
    (*(void (__thiscall **)(volatile __int32))(*(_DWORD *)v3 + 16))(v3);
    return (volatile __int32 *)((int (__thiscall *)(vostok::logging::base_fs_device *, volatile __int32))v1->m_device->close_file)(
                                 v1->m_device,
                                 v3);
  }
  return result;
}
