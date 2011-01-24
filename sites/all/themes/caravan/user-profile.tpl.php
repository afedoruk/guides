<div class='profile'>
<div class='col-1'>
<h3>На нашем сайте</h3>
<?=$profile['user_picture']?>
Имя пользователя: <strong><?=$account->name?></strong><br/>
Зарегистрирован: <strong><?=format_date($account->created, "custom", "d/m/Y")?></strong><br/>
<?
if(user_access("write privatemsg"))
{
	echo l("Написать сообщение", "messages/new/".$account->uid, array("query"=>"user/".$account->uid))."<br/>";
}
?>
<div class='clear-block'></div>
<?
if(isset($profile['guide']))
{
?>
<h3>Карточка гида</h3>
<div class='guide-preview'>
<ul class='img-list'><?=$profile['guide']?></ul>
</div>
<?
}
?>
</div>
<div class='col-2'>
<?
if(isset($profile['testimonials']))
{
?>
<h3>Написал отзывы</h3>
<?
	echo $profile['testimonials'];
}
?>
</div>
</div>