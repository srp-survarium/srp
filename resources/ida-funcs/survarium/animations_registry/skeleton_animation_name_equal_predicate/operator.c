BOOL __usercall survarium::animations_registry::skeleton_animation_name_equal_predicate::operator()@<eax>(
        const survarium::animations_registry::animations_tuple *left@<edi>,
        const survarium::animations_registry::animations_tuple *right@<eax>,
        vostok::resources::resource_base *a3@<ecx>)
{
  char *m_begin; // ebx
  vostok::resources::resource_base *v5; // ecx
  vostok::fs_new::virtual_path_string *v6; // eax
  vostok::resources::resource_base *v7; // ecx
  char *v8; // esi
  vostok::resources::resource_base *v9; // ecx
  vostok::fs_new::virtual_path_string *v10; // eax
  BOOL result; // eax
  vostok::fs_new::virtual_path_string v12; // [esp+8h] [ebp-450h] BYREF
  vostok::fs_new::virtual_path_string v13; // [esp+11Ch] [ebp-33Ch] BYREF
  vostok::fs_new::virtual_path_string v14; // [esp+230h] [ebp-228h] BYREF
  vostok::fs_new::virtual_path_string v15; // [esp+344h] [ebp-114h] BYREF

  m_begin = vostok::resources::resource_base::reusable_request_name(a3, (int)right->first_view.m_object, &v14)->m_string.m_begin;
  v6 = vostok::resources::resource_base::reusable_request_name(v5, (int)left->first_view.m_object, &v12);
  result = 0;
  if ( !vostok::strings::compare(v6->m_string.m_begin, m_begin) )
  {
    v8 = vostok::resources::resource_base::reusable_request_name(v7, (int)right->third_view.m_object, &v13)->m_string.m_begin;
    v10 = vostok::resources::resource_base::reusable_request_name(v9, (int)left->third_view.m_object, &v15);
    if ( !vostok::strings::compare(v10->m_string.m_begin, v8) )
      return 1;
  }
  return result;
}
