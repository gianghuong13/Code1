void drawEggGained(LTexture gEggPic,
	LTexture gEggGainedScore, 
	SDL_Color textColor, 
	SDL_Renderer *gRenderer, 
	TTF_Font *gFont, 
	const int& egggained)
{
	gEggPic.Render(330, 50 ,gRenderer);
	if (gEggGainedScore.loadFromRenderedText(std::to_string(egggained), gFont, textColor, gRenderer))
	{
		gEggGainedScore.Render(400, TEXT_2_POSY,gRenderer);
	}
}

void drawPlayerScore(LTexture gScoreTexture,
	SDL_Color textColor,
	SDL_Renderer *gRenderer,
	TTF_Font *gFont, 
	const int& score)
{
	if (gScoreTexture.loadFromRenderedText(std::to_string(score), gFont, textColor, gRenderer))
	{
		gScoreTexture.Render(SCORE_POSX, SCORE_POSY, gRenderer);
	}
}

void drawPlayerHighScore(LTexture gTextTexture,
	LTexture gHighScoreTexture, 
	SDL_Color textColor, 
	SDL_Renderer* gRenderer, 
	TTF_Font* gFont, 
	const std::string& HighScore)
{
	gTextTexture.Render(TEXT_2_POSX, TEXT_2_POSY, gRenderer);
	if (gHighScoreTexture.loadFromRenderedText(HighScore, gFont, textColor, gRenderer))
	{
		gHighScoreTexture.Render(HIGH_SCORE_POSX, HIGH_SCORE_POSY, gRenderer);
	}
}

void drawEndGameSelection(LTexture gLoseTextTexture,
	LTexture gIntructTextTexture,
	SDL_Event *e, 
	SDL_Renderer *gRenderer,
	bool &Play_Again)
{
	if (Play_Again)
	{
		bool End_Game = false;
		while (!End_Game)
		{
			while (SDL_PollEvent(e) != 0)
			{
				if (e->type == SDL_QUIT)
				{
					Play_Again = false;
				}

				if (e->type == SDL_KEYDOWN)
				{
					switch (e->key.keysym.sym)
					{
					case SDLK_SPACE:
						End_Game = true;
						break;
					case SDLK_ESCAPE:
						End_Game = true;
						Play_Again = false;
						break;
					}
				}
			}

			gLoseTextTexture.Render(400, 150, gRenderer);
			gIntructTextTexture.Render(150, 200, gRenderer);
			SDL_RenderPresent(gRenderer);
		}
	}
}

