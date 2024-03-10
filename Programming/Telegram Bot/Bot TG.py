import telebot
from telebot import types
import webbrowser

bot = telebot.TeleBot('6781441720:AAEbLicAHQIg34uVhyDL_ksAi7uxHtNdsBQ')

@bot.message_handler(commands=['start'])
def get_command_message(message):
    markup = types.InlineKeyboardMarkup()
    button_site = types.InlineKeyboardButton('Перейти на сайт', url='https://rtlalliance.com/')
    button_search = types.InlineKeyboardButton('Отследить груз', callback_data='search')
    button_help = types.InlineKeyboardButton('Помощь', callback_data='help')
    markup.add(button_search)
    markup.row(button_site, button_help)
    bot.send_message(message.chat.id, f"Приветствую, {message.from_user.first_name}!\nЯ автоматический бот компании <a href='https://rtlalliance.com/'>RTL Alliance</a> для отслеживания груза.\n\nЕсли желаете узнать, где находится груз на данный момент, напишите /track\n\nЧтобы узнать дополнительные команды бота, напишите /help", parse_mode='html', reply_markup=markup)

@bot.callback_query_handler(func=lambda call: True)
def callback_message(call):
    if call.data == 'search':
        bot.send_message(call.message.chat.id, 'Введите трек-номер')
    elif call.data == 'help':
        bot.send_message(call.message.chat.id, f'Вот список команд для бота:\n/track - Предоставляет данные о текущем местоположении груза.\n/fulltrack - Предоставляет полную историю перевозки груза.\n/site - Перенаправляет на сайт компании.')

bot.infinity_polling()