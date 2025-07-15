bool __usercall survarium::animations_registry::skeleton_animation_name_less_predicate::operator()@<al>(
        const survarium::animations_registry::animations_tuple *left@<edi>,
        const survarium::animations_registry::animations_tuple *right@<eax>,
        vostok::resources::resource_base *a3@<ecx>)
{
  char *m_begin; // ebx
  vostok::resources::resource_base *v5; // ecx
  vostok::fs_new::virtual_path_string *v6; // eax
  int v7; // eax
  vostok::resources::resource_base *v8; // ecx
  char *v9; // esi
  vostok::resources::resource_base *v10; // ecx
  vostok::fs_new::virtual_path_string *v11; // eax
  vostok::fs_new::virtual_path_string v13; // [esp+8h] [ebp-228h] BYREF
  vostok::fs_new::virtual_path_string v14; // [esp+11Ch] [ebp-114h] BYREF

  m_begin = vostok::resources::resource_base::reusable_request_name(a3, (int)right->first_view.m_object, &v13)->m_string.m_begin;
  v6 = vostok::resources::resource_base::reusable_request_name(v5, (int)left->first_view.m_object, &v14);
  v7 = vostok::strings::compare(v6->m_string.m_begin, m_begin);
  if ( !v7 )
  {
    v9 = vostok::resources::resource_base::reusable_request_name(v8, (int)right->third_view.m_object, &v14)->m_string.m_begin;
    v11 = vostok::resources::resource_base::reusable_request_name(v10, (int)left->third_view.m_object, &v13);
    v7 = vostok::strings::compare(v11->m_string.m_begin, v9);
  }
  return v7 < 0;
}
