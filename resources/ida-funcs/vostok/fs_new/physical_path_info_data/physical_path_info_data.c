void __userpurge vostok::fs_new::physical_path_info_data::physical_path_info_data(
        vostok::fs_new::physical_path_info_data *this@<ecx>,
        int a2@<edi>,
        const vostok::fs_new::physical_path_info_data *__that)
{
  *(_QWORD *)a2 = __that->file_size;
  *(_DWORD *)(a2 + 8) = __that->last_time_of_write;
  *(_DWORD *)(a2 + 12) = __that->type;
  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)(a2 + 16), &__that->path.m_string);
  *(_BYTE *)(a2 + 288) = 92;
  *(_DWORD *)(a2 + 292) = __that->path_type;
}


void __usercall vostok::fs_new::physical_path_info_data::physical_path_info_data(
        vostok::fs_new::physical_path_info_data *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)a2 = -1;
  *(_DWORD *)(a2 + 4) = -1;
  *(_DWORD *)(a2 + 8) = -1;
  *(_DWORD *)(a2 + 12) = 0;
  vostok::fs_new::native_path_string::native_path_string((vostok::fs_new::native_path_string *)(a2 + 16));
  *(_DWORD *)(a2 + 292) = 0;
}
