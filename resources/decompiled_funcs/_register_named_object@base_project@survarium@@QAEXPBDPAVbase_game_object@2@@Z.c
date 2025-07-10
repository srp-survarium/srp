void __userpurge survarium::base_project::register_named_object(
        survarium::base_project *this@<ecx>,
        int a2@<eax>,
        const char *name,
        survarium::base_game_object *obj)
{
  survarium::base_game_object **v4; // eax

  v4 = stlp_std::map<vostok::fixed_string<260>,survarium::base_game_object *,stlp_std::less<vostok::fixed_string<260>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::operator[]<char const *>(
         (stlp_std::map<vostok::fixed_string<260>,survarium::base_game_object *,stlp_std::less<vostok::fixed_string<260> >,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *> > > *)(a2 + 4),
         &name);
  *v4 = obj;
}
