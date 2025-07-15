int __userpurge vostok::animation::skeleton::get_bone_index@<eax>(
        vostok::animation::skeleton *this@<ecx>,
        int a2@<eax>,
        char *name)
{
  return ((int)&stlp_std::priv::__find_if<vostok::animation::skeleton_bone const *,bone_id_predicate>(
                  (const vostok::animation::skeleton_bone *)(a2 + 272),
                  (const vostok::animation::skeleton_bone *)(28 * *(_DWORD *)(a2 + 264) + a2 + 272),
                  name)[-9]
        - a2
        - 20)
       / 28;
}
