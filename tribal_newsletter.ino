
#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#include <avr/pgmspace.h>

#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
// Then see setup() function regarding serial & printer begin() calls.

// Here's the syntax for hardware serial (e.g. Arduino Due) --------------
// Un-comment the following line if using hardware serial:

//Adafruit_Thermal printer(&Serial1);      // Or Serial2, Serial3, etc.

// -----------------------------------------------------------------------


// button setup 
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0; 
boolean printing = false;

// put quotes into PROGMEM
const char quote_1[] PROGMEM = "People don't buy what you do; they buy why you do it. And what you do simply proves what you believe";
const char quote_2[] PROGMEM = "There are only two ways to influence human behavior: you can manipulate it or you can inspire it.";
const char quote_3[] PROGMEM = "Very few people or companies can clearly articulate WHY they do WHAT they do. By WHY I mean your purpose, cause or belief - WHY does your company exist? WHY do you get out of bed every morning? And WHY should anyone care?";
const char quote_4[] PROGMEM = "People don't buy WHAT you do, they buy WHY you do it.";
const char quote_5[] PROGMEM = "We are drawn to leaders and organizations that are good at communicating what they believe. Their ability to make us feel like we belong, to make us feel special, safe and not alone is part of what gives them the ability to inspire us.";
const char quote_6[] PROGMEM = "For values or guiding principles to be truly effective they have to be verbs. It's not \"integrity,\" it's \"always do the right thing.\" It's not \"innovation,\" it's \"look at the problem from a different angle.\" Articulating our values as verbs gives us a clear idea - we have a clear idea of how to act in any situation.";
const char quote_7[] PROGMEM = "Happy employees ensure happy customers. And happy customers ensure happy shareholders - in that order.";
const char quote_8[] PROGMEM = "Leading is not the same as being the leader. Being the leader means you hold the highest rank, either by earning it, good fortune or navigating internal politics. Leading, however, means that others willingly follow you - not because they have to, not because they are paid to, but because they want to.";
const char quote_9[] PROGMEM = "You don't hire for skills, you hire for attitude. You can always teach skills.";
const char quote_10[] PROGMEM = "Great companies don't hire skilled people and motivate them, they hire already motivated people and inspire them. People are either motivated or they are not. Unless you give motivated people something to believe in, something bigger than their job to work toward, they will motivate themselves to find a new job and you'll be stuck with whoever's left.";
const char quote_11[] PROGMEM = "Trust is maintained when values and beliefs are actively managed. If companies do not actively work to keep clarity, discipline and consistency in balance, then trust starts to break down.";
const char quote_12[] PROGMEM = "All organizations start with WHY, but only the great ones keep their WHY clear year after year";
const char quote_13[] PROGMEM = "If your actions inspire others to dream more, learn more, do more and become more, you are a leader.";
const char quote_14[] PROGMEM = "Great companies don't hire skilled people and motivate them, they hire already motivated people and inspire them.";
const char quote_15[] PROGMEM = "If you hire people just because they can do a job, they'll work for your money. But if you hire people who believe what you believe, they'll work for you with blood and sweat and tears.";
const char quote_16[] PROGMEM = "You can easily judge the character of a man by how he treats those who can do nothing for him.";
const char quote_17[] PROGMEM = "Working hard for something we don't care about is called stress: Working hard for something we love is called passion.";
const char quote_18[] PROGMEM = "he true price of leadership is the willingness to place the needs of others above your own. Great leaders truly care about those they are privileged to lead and understand that the true cost of the leadership privilege comes at the expense of self-interest.";
const char quote_19[] PROGMEM = "The role of a leader is not to come up with all the great ideas. The role of a leader is to create an environment in which great ideas can happen.";
const char quote_20[] PROGMEM = "As the Zen Buddhist saying goes, how you do anything is how you do everything.";
const char quote_21[] PROGMEM = "Leadership requires two things: a vision of the world that does not yet exist and the ability to communicate it.";
const char quote_22[] PROGMEM = "When you compete against everyone else, no one wants to help you. But when you compete against yourself, everyone wants to help you.";
const char quote_23[] PROGMEM = "A star wants to see himself rise to the top. A leader wants to see those around him rise to the top.";
const char quote_24[] PROGMEM = "Some in management positions operate as if they are in a tree of monkeys. They make sure that everyone at the top of the tree looking down sees only smiles. But all too often, those at the bottom looking up see only asses.";
const char quote_25[] PROGMEM = "Returning from work feeling inspired, safe, fulfilled and grateful is a natural human right to which we are all entitled and not a modern luxury that only a few lucky ones are able to find.";
const char quote_26[] PROGMEM = "two ways to influence human behavior: you can manipulate it or you can inspire it.";
const char quote_27[] PROGMEM = "And when a leader embraces their responsibility to care for people instead of caring for numbers, then people will follow, solve problems and see to it that that leader's vision comes to life the right way, a stable way and not the expedient way.";
const char quote_28[] PROGMEM = "Henry Ford summed it up best. \"If I had asked people what they wanted,\" he said, \"they would have said a faster horse.";
const char quote_29[] PROGMEM = "Value is not determined by those who set the price. Value is determined by those who choose to pay it.";
const char quote_30[] PROGMEM = "It is not the genius at the top giving directions that makes people great. It is great people that make the guy at the top look like a genius.";
const char quote_31[] PROGMEM = "Charisma has nothing to do with energy; it comes from a clarity of WHY. It comes from absolute conviction in an ideal bigger than oneself. Energy, in contrast, comes from a good night's sleep or lots of caffeine. Energy can excite. But only charisma can inspire. Charisma commands loyalty. Energy does not.";
const char quote_32[] PROGMEM = "A boss wants to pay for results, an employee wants recognition for effort. If a boss recognizes effort, they will get even better results.";
const char quote_33[] PROGMEM = "Let us all be the leaders we wish we had.";
const char quote_34[] PROGMEM = "Great leaders and great organizations are good at seeing what most of us can't see. They are good at giving us things we would never think of asking for.";
const char quote_35[] PROGMEM = "If our leaders are to enjoy the trappings of their position in the hierarchy, then we expect them to offer us protection. The problem is, for many of the overpaid leaders, we know that they took the money and perks and didn't offer protection to their people. In some cases, they even sacrificed their people to protect or boost their own interests. This is what so viscerally offends us. We only accuse them of greed and excess when we feel they have violated the very definition of what it means to be a leader.";
const char quote_36[] PROGMEM = "A leader must be inspired by the people before a leader can inspire the people.";
const char quote_37[] PROGMEM = "Children are better off having a parent who works into the night in a job they love than a parent who works shorter hours but comes home unhappy.";

PGM_P const simon_quote_table[] PROGMEM =
  {
    quote_1,
    quote_2,
    quote_3,
    quote_4,
    quote_5,
    quote_6,
    quote_7,
    quote_8,
    quote_9,
    quote_10,
    quote_11,
    quote_12,
    quote_13,
    quote_14,
    quote_15,
    quote_16,
    quote_17,
    quote_18,
    quote_19,
    quote_20,
    quote_21,
    quote_22,
    quote_23,
    quote_24,
    quote_25,
    quote_26,
    quote_27,
    quote_28,
    quote_29,
    quote_30,
    quote_31,
    quote_32,
    quote_33,
    quote_34,
    quote_35,
    quote_36,
    quote_37
};

// old mike
const char mike_quote_1[] PROGMEM = "Some people want it to happen, some wish it would happen, others make it happen.";
const char mike_quote_2[] PROGMEM = "I can accept failure, everyone fails at something. But I can't accept not trying.";
const char mike_quote_3[] PROGMEM = "To be successful you have to be selfish, or else you never achieve. And once you get to your highest level, then you have to be unselfish.; Stay reachable. Stay in touch. Don't isolate.";
const char mike_quote_4[] PROGMEM = "You have to expect things of yourself before you can do them.";
const char mike_quote_5[] PROGMEM = "If you accept the expectations of others, especially negative ones, then you never will change the outcome.";
const char mike_quote_6[] PROGMEM = "Talent wins games, but teamwork and intelligence wins championships.";
const char mike_quote_7[] PROGMEM = "The good part about being famous is being able to help people. The hard part is every day you have to be in a good mood, because that is what; people expect. You learn to get good at it.";
const char mike_quote_8[] PROGMEM = "I play to win, whether during practice or a real game. And I will not let anything get in the way of me and my competitive enthusiasm to win.";
const char mike_quote_9[] PROGMEM = "There is no 'i' in team but there is in win.";
const char mike_quote_10[] PROGMEM = "Sometimes, things may not go your way, but the effort should be there every single night.";
const char mike_quote_11[] PROGMEM = "If you quit once it becomes a habit. Never quit!";
const char mike_quote_12[] PROGMEM = "Sometimes you need to get hit in the head to realize that you're in a fight.";
const char mike_quote_13[] PROGMEM = "I built my talents on the shoulders of someone else's talent.";
const char mike_quote_14[] PROGMEM = "I believe greatness is an evolutionary process that changes and evolves era to era.";
const char mike_quote_15[] PROGMEM = "In any investment, you expect to have fun and make money.";
const char mike_quote_16[] PROGMEM = "My heroes are and were my parents. I can't see having anyone else as my heroes.";
const char mike_quote_17[] PROGMEM = "I wasn't really a work-conscious type of person. I was a player. I loved to play sports.";
const char mike_quote_18[] PROGMEM = "There's only one Michael Jordan.";
const char mike_quote_19[] PROGMEM = "I know the signs of scaredness.";
const char mike_quote_20[] PROGMEM = "Being Michael Jordan means acting the same as I always have. ";
const char mike_quote_21[] PROGMEM = "I realized that if I was going to achieve anything in life I had to be aggressive. I had to get out there and go for it.";
const char mike_quote_22[] PROGMEM = "I realize that I'm black, but I like to be viewed as a person, and this is everybody's wish.";
const char mike_quote_23[] PROGMEM = "If you're trying to achieve, there will be roadblocks. I've had them; everybody has had them. But obstacles don't have to stop you. If you; run into a wall, don't turn around and give up. Figure out how to climb it, go through it, or work around it.";
const char mike_quote_24[] PROGMEM = "My father used to say that it's never too late to do anything you wanted to do. And he said, 'You never know what you can accomplish until; you try.";
const char mike_quote_25[] PROGMEM = "To be successful you have to be selfish, or else you never achieve. And once you get to your highest level, then you have to be unselfish.; Stay reachable. Stay in touch. Don't isolate.";
const char mike_quote_26[] PROGMEM = "To learn to succeed, you must first learn to fail.";
const char mike_quote_27[] PROGMEM = "I never looked at the consequences of missing a big shot… when you think about the consequences you always think of a negative result.";
const char mike_quote_28[] PROGMEM = "The game has its ups and downs, but you can never lose focus of your individual goals and you can't let yourself be beat because of lack of; effort.";
const char mike_quote_29[] PROGMEM = "You have competition every day because you set such high standards for yourself that you have to go out every day and live up to that.";
const char mike_quote_30[] PROGMEM = "I want to wake up every day and do whatever comes in my mind, and not feel pressure or obligations to do anything else in my life.";
const char mike_quote_31[] PROGMEM = "Live the moment for the moment.";
const char mike_quote_32[] PROGMEM = "I'm not out there sweating for three hours every day just to find out what it feels like to sweat.";
const char mike_quote_33[] PROGMEM = "My attitude is that if you push me towards something that you think is a weakness, then I will turn that perceived weakness into a strength.";
const char mike_quote_34[] PROGMEM = "I've missed more than 9000 shots in my career. I've lost almost 300 games. 26 times, I've been trusted to take the game winning shot and; missed. I've failed over and over and over again in my life. And that is why I succeed.";
const char mike_quote_35[] PROGMEM = "It's absolutely wrong that I don't want guys to challenge me. And the people who say that aren't in the room.";
const char mike_quote_36[] PROGMEM = "Winning isn't always championships.";
const char mike_quote_37[] PROGMEM = "Be true to the game, because the game will be true to you. If you try to shortcut the game, then the game will shortcut you. If you put forth; the effort, good things will be bestowed upon you. That's truly about the game, and in some ways that's about life too.";
const char mike_quote_38[] PROGMEM = "You're a loser. You've always been a loser.";
const char mike_quote_39[] PROGMEM = "You're going to play from the little girls' tees?";
const char mike_quote_40[] PROGMEM = "They don't need a ticket to watch you sitting on the bench. They can go to your house for that.";
const char mike_quote_41[] PROGMEM = "I've always believed that if you put in the work, the results will come. I don't do things half-heartedly. Because I know if I do, then I can; expect half-hearted results.";
const char mike_quote_42[] PROGMEM = "Don't let them drag you down by rumors just go with what you believe in.";
const char mike_quote_43[] PROGMEM = "Gambling is legal and betting is legal, for what I bet.";
const char mike_quote_44[] PROGMEM = "I can't speak for the future. I have no crystal ball.";
const char mike_quote_45[] PROGMEM = "Once I made a decision, I never thought about it again.";
const char mike_quote_46[] PROGMEM = "It is easy to choose a path of anonymity and lead an empty life. But to strive hard and lead an impactful life, one needs a burning desire to; realize dreams.";
const char mike_quote_47[] PROGMEM = "What is love? Love is playing every game as if it's your last!";
const char mike_quote_48[] PROGMEM = "The basketball court for me, during a game, is the most peaceful place I can imagine. On the basketball court, I worry about nothing. When; I'm out there, no one can bother me.";
const char mike_quote_49[] PROGMEM = "If I had been playing for money I would have complained a long time ago that I was underpaid.";
const char mike_quote_50[] PROGMEM = "I won't have any competitive instincts in any sports, other than golf. I can't see being competitive in sports any more.";
const char mike_quote_51[] PROGMEM = "Never say never, because limits, like fears, are often just an illusion.";
const char mike_quote_52[] PROGMEM = "It is nerve-wracking watching my kids' games.";
const char mike_quote_53[] PROGMEM = "The minute you get away from fundamentals – whether it's proper technique, work ethic or mental preparation – the bottom can fall out of your; game, your schoolwork, your job, whatever you're doing.";
const char mike_quote_54[] PROGMEM = "I think the players win the championship, and the organization has something to do with it, don't get me wrong. But don't try to put the; organization above the players.";
const char mike_quote_55[] PROGMEM = "It's hard to say if the NBA is hurt by the influx of younger players, but it's definitely impacted the league.";
const char mike_quote_56[] PROGMEM = "I've never been afraid to fail.";
const char mike_quote_57[] PROGMEM = "If it turns out that my best wasn't good enough, at least I won't look back and say I was afraid to try.";
const char mike_quote_58[] PROGMEM = "It's heavy duty to try to do everything and please everybody. My job was to go out there and play the game of basketball as best I can.; People may not agree with that. I can't live with what everyone's impression of what I should or what I shouldn't do.";
const char mike_quote_59[] PROGMEM = "As athletes, we're used to reacting quickly. Here, it's 'come, stop, come, stop.' There's a lot of downtime. That's the toughest part of the; day.";
const char mike_quote_60[] PROGMEM = "The game of basketball has been everything to me. My place of refuge, place I've always gone where I needed comfort and peace. It's been the; site of intense pain and the most intense feelings of joy and satisfaction. It's a relationship that has evolved over time, given me the greatest respect and love for the game.";
const char mike_quote_61[] PROGMEM = "Always turn a negative situation into a positive situation.";
const char mike_quote_62[] PROGMEM = "In reality, I never want to grow up.";
const char mike_quote_63[] PROGMEM = "There is no such thing as a perfect basketball player, and I don't believe there is only one greatest player either.";
const char mike_quote_64[] PROGMEM = "I never thought a role model should be negative.";
const char mike_quote_65[] PROGMEM = "The key to success is failure.";
const char mike_quote_66[] PROGMEM = "You have to expect things of yourself before you can do them.";
const char mike_quote_67[] PROGMEM = "I want to be the bridge to the next generation.";
const char mike_quote_68[] PROGMEM = "I own the guy guarding me.";
const char mike_quote_69[] PROGMEM = "How many times have your parents told you not to do things, and the next thing you know, you go do it? And you realized you shouldn't have; done it.";
const char mike_quote_70[] PROGMEM = "I know fear is an obstacle for some people, but it is an illusion to me. Failure always made me try harder the next time.";
const char mike_quote_71[] PROGMEM = "If you do the work you get rewarded. There are no shortcuts in life.";
const char mike_quote_72[] PROGMEM = "I want to be perceived as a guy who played his best in all facets, not just scoring. A guy who loved challenges.";
const char mike_quote_73[] PROGMEM = "You can practice shooting 8 hours a day, but if your technique is wrong, then all you become is very good at shooting the wrong way. Get the; fundamentals down and the level of everything you do will rise.";
const char mike_quote_74[] PROGMEM = "My challenge when I came back was to face the young talent, to dissect their games, and show them maybe that they needed to learn more about; the game than just the money aspect.";
const char mike_quote_75[] PROGMEM = "Failure is acceptable. but not trying is a whole different ball park.";
const char mike_quote_76[] PROGMEM = "Everybody has talent, but ability takes hard work.";
const char mike_quote_77[] PROGMEM = "Best evaluation I can make of a player is to look in his eyes and see how scared they are.";
const char mike_quote_78[] PROGMEM = "My mother is my root, my foundation. She planted the seed that I base my life on, and that is the belief that the ability to achieve starts; in your mind.";
const char mike_quote_79[] PROGMEM = "The best come from the worst.";
const char mike_quote_80[] PROGMEM = "Marcelo is the new Jordan";
const char mike_quote_81[] PROGMEM = "Champions do not become champions when they win an event, but in the hours, weeks, and months, and years they spend preparing for it. The; victorious performance itself is merely a demonstration of their championship character.";
const char mike_quote_82[] PROGMEM = "Enjoy every minute of life. Never second-guess life.";
const char mike_quote_83[] PROGMEM = "I mean we all fly. Once you leave the ground, you fly. Some people fly longer than others.";
const char mike_quote_84[] PROGMEM = "When I will lose the sense of motivation and the sense to prove something as a basketball player, it's time for me to move away from the game.";
const char mike_quote_85[] PROGMEM = "Learning's a gift, even when pain is your teacher.";
const char mike_quote_86[] PROGMEM = "People ask me if I could fly, I said, \"yeah…. for a little while.\"";
const char mike_quote_87[] PROGMEM = "Heart is what separates the good from the great.";
const char mike_quote_88[] PROGMEM = "The game is my wife. It demands loyalty and responsibility, and it gives me back fulfillment and peace.";
const char mike_quote_89[] PROGMEM = "Do I need my number retired throughout the course of the league to acknowledge what I've done? No.";
const char mike_quote_90[] PROGMEM = "I would tell players to relax and never think about what's at stake. Just think about the basketball game. If you start to think about who is; going to win the championship, you've lost your focus.";
const char mike_quote_91[] PROGMEM = "My body could stand the crutches but my mind couldn't stand the sideline.";
const char mike_quote_92[] PROGMEM = "Just play. Have fun. Enjoy the game.";
const char mike_quote_93[] PROGMEM = "In college I never realized the opportunities available to a pro athlete. I've been given the chance to meet all kinds of people, to travel; and expand my financial capabilities, to get ideas and learn about life, to create a world apart from basketball.";
const char mike_quote_94[] PROGMEM = "I hope the millions of people I've touched have the optimism and desire to share their goals and hard work and perseverance with a positive; attitude.";
const char mike_quote_95[] PROGMEM = "Even when I'm old and gray, I won't be able to play it, but I'll still love the game.";
const char mike_quote_96[] PROGMEM = "I'd like to be settled into somewhat of a normal life. Somewhat. I know it's never going to be completely normal.";
const char mike_quote_97[] PROGMEM = "Every time I feel tired while I am exercising and training, I close my eyes to see that picture, to see that list with my name. This usually; motivates me to work again.";
const char mike_quote_98[] PROGMEM = "When I was young, I had to learn the fundamentals of basketball. You can have all the physical ability in the world, but you still have to; know the fundamentals.";
const char mike_quote_99[] PROGMEM = "Not every flying hero has a cape.";
const char mike_quote_100[] PROGMEM = "For a competitive junkie like me, golf is a great solution because it smacks you in the face every time you think you've accomplished; something. That to me has taken over a lot of the energy and competitiveness for basketball.";
const char mike_quote_101[] PROGMEM = "I will not quit this game because of what the media has done to me.";
const char mike_quote_102[] PROGMEM = "Playing sick. That is so hard to do. It has to be a total mental challenge, as well as the physical challenge.";
const char mike_quote_103[] PROGMEM = "I like control.";
const char mike_quote_104[] PROGMEM = "I want to play for years.";


PGM_P const mike_quote_table[] PROGMEM =
  {
    mike_quote_1,
    mike_quote_2,
    mike_quote_3,
    mike_quote_4,
    mike_quote_5,
    mike_quote_6,
    mike_quote_7,
    mike_quote_8,
    mike_quote_9,
    mike_quote_10,
    mike_quote_11,
    mike_quote_12,
    mike_quote_13,
    mike_quote_14,
    mike_quote_15,
    mike_quote_16,
    mike_quote_17,
    mike_quote_18,
    mike_quote_19,
    mike_quote_20,
    mike_quote_21,
    mike_quote_22,
    mike_quote_23,
    mike_quote_24,
    mike_quote_25,
    mike_quote_26,
    mike_quote_27,
    mike_quote_28,
    mike_quote_29,
    mike_quote_30,
    mike_quote_31,
    mike_quote_32,
    mike_quote_33,
    mike_quote_34,
    mike_quote_35,
    mike_quote_36,
    mike_quote_37,
    mike_quote_38,
    mike_quote_39,
    mike_quote_40,
    mike_quote_41,
    mike_quote_42,
    mike_quote_43,
    mike_quote_44,
    mike_quote_45,
    mike_quote_46,
    mike_quote_47,
    mike_quote_48,
    mike_quote_49,
    mike_quote_50,
    mike_quote_51,
    mike_quote_52,
    mike_quote_53,
    mike_quote_54,
    mike_quote_55,
    mike_quote_56,
    mike_quote_57,
    mike_quote_58,
    mike_quote_59,
    mike_quote_60,
    mike_quote_61,
    mike_quote_62,
    mike_quote_63,
    mike_quote_64,
    mike_quote_65,
    mike_quote_66,
    mike_quote_67,
    mike_quote_68,
    mike_quote_69,
    mike_quote_70,
    mike_quote_71,
    mike_quote_72,
    mike_quote_73,
    mike_quote_74,
    mike_quote_75,
    mike_quote_76,
    mike_quote_77,
    mike_quote_78,
    mike_quote_79,
    mike_quote_80,
    mike_quote_81,
    mike_quote_82,
    mike_quote_83,
    mike_quote_84,
    mike_quote_85,
    mike_quote_86,
    mike_quote_87,
    mike_quote_88,
    mike_quote_89,
    mike_quote_90,
    mike_quote_91,
    mike_quote_92,
    mike_quote_93,
    mike_quote_94,
    mike_quote_95,
    mike_quote_96,
    mike_quote_97,
    mike_quote_98,
    mike_quote_99,
    mike_quote_100,
    mike_quote_101,
    mike_quote_102,
    mike_quote_103,
    mike_quote_104
  };

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);

  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(19200);  // Initialize SoftwareSerial
  //Serial1.begin(19200); // Use this instead if using hardware serial
  printer.begin();        // Init printer (same regardless of serial type)
  Serial.begin(19200);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  
  if ((printing == false) && (buttonState == 0)) {
    printMikeQuote();
  }
  
}

void printMikeQuote() {

  printing = true;

  char buffer[1000];
  strcpy_P(buffer, (PGM_P)pgm_read_word(&(mike_quote_table[random(0, 103)])));
  
  printer.wake(); 
  printer.feed(5);
  printer.justify('C');
  printer.println(buffer); 
  printer.feed(2);
  printer.boldOn();
  printer.setSize('S');
  printer.println(F("Old Mike"));
  printer.boldOff();
  printer.feed(5);
  printer.sleep();

  printing = false;
  
}

void printSimonQuote() {

  char buffer[1000];
  strcpy_P(buffer, (PGM_P)pgm_read_word(&(simon_quote_table[random(0, 37)])));
  
  printer.wake(); 
  printer.feed(5);
  printer.justify('C');
  printer.println(buffer); 
  printer.feed(2);
  printer.boldOn();
  printer.setSize('S');
  printer.println(F("Simon Sinek"));
  printer.boldOff();
  printer.feed(5);
  printer.sleep();
  
}

void printTest() {
   // Test inverse on & off
  printer.inverseOn();
  printer.println(F("Inverse ON"));
  printer.inverseOff();

  // Test character double-height on & off
  printer.doubleHeightOn();
  printer.println(F("Double Height ON"));
  printer.doubleHeightOff();

  // Set text justification (right, center, left) -- accepts 'L', 'C', 'R'
  printer.justify('R');
  printer.println(F("Right justified"));
  printer.justify('C');
  printer.println(F("Center justified"));
  printer.justify('L');
  printer.println(F("Left justified"));

  // Test more styles
  printer.boldOn();
  printer.println(F("Bold text"));
  printer.boldOff();

  printer.underlineOn();
  printer.println(F("Underlined text"));
  printer.underlineOff();

  printer.setSize('L');        // Set type size, accepts 'S', 'M', 'L'
  printer.println(F("Large"));
  printer.setSize('M');
  printer.println(F("Medium"));
  printer.setSize('S');
  printer.println(F("Small"));

  printer.justify('C');
  printer.println(F("normal\nline\nspacing"));
  printer.setLineHeight(50);
  printer.println(F("Taller\nline\nspacing"));
  printer.setLineHeight(); // Reset to default
  printer.justify('L');


  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults
}
