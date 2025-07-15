void __thiscall survarium::base_project::register_named_object(
        survarium::base_project *this,
        const char *const *name,
        survarium::base_game_object *obj,
        survarium::base_game_object *a4)
{
  survarium::base_game_object **v4; // eax

  v4 = stlp_std::map<vostok::fixed_string<260>,survarium::base_game_object *,stlp_std::less<vostok::fixed_string<260>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::operator[]<char const *>(
         (stlp_std::map<vostok::fixed_string<260>,survarium::base_game_object *,stlp_std::less<vostok::fixed_string<260> >,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *> > > *)this,
         (stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260> >,stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *> > > *)(name + 1),
         (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> > >)&obj);
  *v4 = a4;
}
