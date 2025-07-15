void __userpurge vostok::render::skeleton_combined_cook_data::skeleton_combined_cook_data(
        vostok::render::skeleton_combined_cook_data *this@<ecx>,
        int a2@<esi>,
        bool owner_cook)
{
  vostok::fs_new::virtual_path_string *v3; // ecx
  vostok::render::skeleton_combined_cook_data::model_def *v4; // edi
  int i; // ebx

  vostok::fs_new::virtual_path_string::virtual_path_string(&this->skeleton_name, a2);
  *(_DWORD *)(a2 + 276) = 0;
  vostok::fs_new::virtual_path_string::virtual_path_string(v3, a2 + 280);
  *(_DWORD *)(a2 + 556) = 0;
  *(_DWORD *)(a2 + 560) = 0;
  v4 = (vostok::render::skeleton_combined_cook_data::model_def *)(a2 + 564);
  for ( i = 7; i >= 0; --i )
    vostok::render::skeleton_combined_cook_data::model_def::model_def(v4++);
  *(_BYTE *)(a2 + 7317) = owner_cook;
}
